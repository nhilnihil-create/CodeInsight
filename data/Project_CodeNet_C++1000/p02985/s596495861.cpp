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
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;

int n, k;
VVI ab;

ll chain(int cs, int par, int anc)
{

    ll rval = 1;
    //cout<<cs<<" "<<par<<" "<<anc<<" "<<rval<<endl;

    int cnt = 0;
    REPALL(i,ab[cs]) {
        //cout<<cs<<"_"<<ab[cs][i]<<endl;
        if (ab[cs][i] == par) {
            continue;
        } else {
            rval = (rval * (k - anc - cnt) % MOD) * (chain(ab[cs][i], cs, min(2, anc + 1))) % MOD;
            cnt++;
        }
    }

    return rval;
}

int main()
{
    cin>>n>>k;
    ab.resize(n+1);
    REP(i,n-1) {
        int a, b;
        cin>>a>>b;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }
    ab[0].push_back(1);
    ab[1].push_back(0);

    cout<<chain(0, 0, 0)<<endl;

    return 0;
}
