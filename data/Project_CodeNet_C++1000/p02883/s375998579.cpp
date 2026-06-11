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
const int INF = 1e7;
const ll MOD = 998244353;
const double pi = 3.141592653589793;

ll n, k, sum_a, ans;
VLL a, f;

bool solve(ll limit, ll tk)
{
    REP(i,n) {
        //cerr<<i<<"_"<<tk<<"  ";
        if (tk < 0) {
            return false;
        } else if (a[i] * f[n-i-1] <= limit) {
            continue;
        } else {
            ll tmp = (a[i] * f[n-i-1] - limit + f[n-i-1] - 1) / f[n-i-1];
            tk -= tmp;
        }
    }
    //cerr<<endl;

    return tk >= 0;
}

int main()
{
    cin>>n>>k;
    a.resize(n);
    f.resize(n);
    REP(i,n) {
        cin>>a[i];
        sum_a += a[i];
    }
    REP(i,n) {
        cin>>f[i];
    }
    SORT(a);
    SORT(f);

    ll l = 0, r = 1e12 + 1, mid;
    REP(i, 100) {
        debug(mid);
        if (l == r) {
            break;
        }

        mid = (l + r) / 2;
        bool feasible = solve(mid, k);
        if (feasible) {
            r = mid;
            cerr<<"true"<<endl;
        } else {
            l = mid;
            cerr<<"false"<<endl;
        }

    }

    cout<<r<<endl;

    return 0;
}
