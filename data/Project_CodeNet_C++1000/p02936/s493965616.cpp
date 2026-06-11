#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

struct node {
    int parent = -1;
    vector<int> child;
    int child_num = 0;
    int counter = 0;
};

vector<node> tree;

void step_counter(int i) {
    // cout << i << " " << tree[i].child_num << endl;
    for (int j = 0; j < tree[i].child_num; j++) {
        int child = tree[i].child[j] - 1;
        if (child != tree[i].parent) {
            tree[child].parent = i;
            tree[child].counter += tree[i].counter;
            // cout << child << " " << tree[child].child_num << endl;
            if (tree[child].child_num != 1) step_counter(child);
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> ab(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    // sort(ab.begin(), ab.end());

    tree.resize(N);
    for (int i = 0; i < Q; i++) {
        int p, tmp;
        cin >> p >> tmp;
        tree[p - 1].counter += tmp;
    }

    for (int i = 0; i < N - 1; i++) {
        tree[ab[i].first - 1].child.push_back(ab[i].second);
        tree[ab[i].second - 1].child.push_back(ab[i].first);
        tree[ab[i].first - 1].child_num++;
        tree[ab[i].second - 1].child_num++;
    }

    step_counter(0);

    for (int i = 0; i < N; i++) {
        cout << tree[i].counter << " ";
    }
    cout << endl;

    return 0;
}
