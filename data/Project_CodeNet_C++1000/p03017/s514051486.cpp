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
    int n, a, b;
    cin >> n >> a >> b;
    a--;b--;
    int c, d;
    cin >> c >> d;
    c--;d--;
    int mx = max(c,d);
    string s; cin >> s;
    int dc = 0, dm = 0;
    int sc = 0, sm = 0;
    bool ans = true;
    FOR(i,a,mx+1){
        if (!((i > a) || (i < c)) && ((i > b) || (i < d))) {
            cerr << i;
            sc = 0;
            continue;
        }
        if (s[i] == '#') {
            sc++;
            sm = max(sm,sc);
            dc = 0;
        } else {
            if (i >= b-1) {
                dc++;
                dm = max(dm,dc);
            }
            sc = 0;
        }
        if (c > d && i == d+1) {
            if (dm <= 2) {
                ans = false;
                break;
            }
        }
        if (sm >= 2) {
            ans = false;
            break;
        }
    }

    ATYN(ans)

    return 0;
}