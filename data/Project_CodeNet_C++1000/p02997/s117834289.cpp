#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, k;
    cin >> n >> k;
    int max_num = n * (n - 1) / 2 - (n - 1);
    if (k > max_num) {
        cout << -1 << endl;
        return 0;
    }
    int rest = max_num - k;
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; ++i) { 
        ans.push_back(make_pair(0, i));
    }
    //cout << max_num << " " << rest << endl;
    for (int i = 1; i < n; ++i) {
        bool flg = false;
        for (int j = i + 1; j < n; ++j) {
            if (rest == 0) break;
            --rest;
            ans.emplace_back(i, j);
        }
    }
    cout << (int)(ans.size()) << endl;
    for (auto a: ans) {
        cout << a.first + 1 << " " << a.second + 1 << endl;
    }
    return 0;
}
