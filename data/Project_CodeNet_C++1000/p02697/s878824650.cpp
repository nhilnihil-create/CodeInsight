#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> ans;
    if (n % 2) {
        for (int l = 1, r = n - 1; l < r; l++, r--)
            ans.emplace_back(l, r);
    }
    else {
        bool flag = false;
        for (int l = 1, r = n - 1; l < r; l++, r--) {
            if (!flag && r - l <= n / 2) {
                r--;
                flag = true;
            }
            ans.emplace_back(l, r);
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}
