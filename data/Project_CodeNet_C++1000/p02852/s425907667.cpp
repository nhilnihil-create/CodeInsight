#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    int i = n;
    vector<int> ans;

    while(true) {
        if (i <= m) {
            ans.push_back(i);
            break;
        }
        bool ng = true;
        for (int j = m; j > 0;j--) {
            if (s[i-j] == '0') {
                ans.push_back(j);
                i -= j;
                ng = false;
                break;
            }
        }
        if (ng) {
            OUT(-1)
            return 0;
        }
    }

    reverse(ALL(ans));
    REP(i,ans.size()) cout << ans[i] << " ";

    return 0;
}