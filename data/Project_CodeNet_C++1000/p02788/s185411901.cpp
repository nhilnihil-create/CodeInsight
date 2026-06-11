#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e10;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;

ll n, d, a, ans;
VLL X;
vector<pair<ll, ll>> monsters;
VLL sum;

int main()
{
    cin>>n>>d>>a;
    sum.resize(n+1);
    REP(i,n) {
        ll x, h;
        cin>>x>>h;
        X.push_back(x);
        monsters.push_back({x, h});
    }
    monsters.push_back({INF, INF});
    SORT(X);
    SORT(monsters);
    REP(i,n) {
        if (monsters[i].e2 > sum[i]) {
            ll tmp = (monsters[i].e2 - sum[i] + a - 1) / a;
            ans += tmp;
            sum[i] += tmp * a;
            int idx = upper_bound(ALL(X), X[i] + 2 * d) - X.begin();
            sum[idx] -= tmp * a;
        }
        //cout<<i<<":"<<ans<<"_"; REPALL(i,sum) cout<<sum[i]<<" "; nextline;

        sum[i+1] += sum[i];
    }

    cout<<ans<<endl;

    return 0;
}
