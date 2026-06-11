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

void mybuild_tree(vector<long long int>& mytree, const vector<long long int>& data, int index, int l, int r) {
    if (l == r) {
        mytree[index] = data[l];
    } else {
        int m = (l + r) / 2;
        mybuild_tree(mytree, data, index * 2 + 1, l, m);
        mybuild_tree(mytree, data, index * 2 + 2, m + 1, r);
        mytree[index] = mytree[index * 2 + 1] + mytree[index * 2 + 2];
    }
}

void myupdate_tree(vector<long long int>& mytree, int index, int l, int r, int target_l, int target_r, int val) {
    if (r < target_l || target_r < l) return;
    if (l == r && l >= target_l && r <= target_r) {
        mytree[index] += val;
        return;
    }

    int m = (l + r) / 2;
    myupdate_tree(mytree, index * 2 + 1, l, m, target_l, target_r, val);
    myupdate_tree(mytree, index * 2 + 2, m + 1, r, target_l, target_r, val);
    mytree[index] = mytree[index * 2 + 1] + mytree[index * 2 + 2];   
}

long long int myquery_tree(vector<long long int>& mytree, int index, int l, int r, int target_l, int target_r) {
    if (r < target_l || l > target_r) return 0;
    if (l >= target_l && r <= target_r) return mytree[index];

    int m = (l + r) / 2;
    long long int res =  myquery_tree(mytree, index * 2 + 1, l, m, target_l, target_r) + myquery_tree(mytree, index * 2 + 2, m + 1, r, target_l, target_r);
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long int> mytree(4 * n + 1, 0);
    vector<long long int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mybuild_tree(mytree, v, 0, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            myupdate_tree(mytree, 0, 0, n - 1, x, x, y);
        } else {
            cout << myquery_tree(mytree, 0, 0, n - 1, x, y - 1) << endl;
        }
    }
}


