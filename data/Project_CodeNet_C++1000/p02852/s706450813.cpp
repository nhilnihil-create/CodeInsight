#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int now = 0;
    vector<int> ans;
    while (now < n) {
        for (int i = min(m, n-now); i >= 1; --i) {
            if (s[now+i] == '0') {
                ans.push_back(i);
                now += i;
                break;
            }
            if (i == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i, ans.size()) printf("%d%c", ans[i], i==n-1?'\n':' ');
}