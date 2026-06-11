#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int myfind(int a, vector<int>& relation) {
    if (relation[a] == a) return a;
    int res = myfind(relation[a], relation);
    relation[a] = res;
    return res;
}

void myunion(int a, int b, vector<int>& relation) {
    int ta = myfind(a, relation);
    int tb = myfind(b, relation);
    if (ta == tb) return;
    relation[ta] = tb;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> relation(n, 0);
    for (int i = 0; i < n; i++) {
        relation[i] = i;
    }
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            myunion(u, v, relation);
        } else {
            if (myfind(u, relation) == myfind(v, relation)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}


