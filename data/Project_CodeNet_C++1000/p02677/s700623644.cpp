#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm> 
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include  <ctime>
#include <iomanip>
using namespace std;

#define ll                    long long int
#define ull                   unsigned long long int
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define rloop(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define eb                    emplace_back
#define ab(a)                 (a<0)?(-1*a):a
#define pc                    putchar
#define gc                    getchar
#define mset(a,b,c)           loop(i,0,b) a[i]=c
#define mp                    make_pair
#define itoc(c)               ((char)(((int)'0')+c))
#define all(p)                p.begin(),p.end()
#define max(x,y)              ((x>y)?x:y)
#define min(x,y)              ((x<y)?x:y)
#define mid(s,e)              (s+(e-s)/2)
#define vi                    vector<int>
#define vvi                   vector<vector<int>>
const ll MOD = 1000000007;

ll modpow(ll a, ll b, ll mod) { ll res = 1; for (; b; b >>= 1) { if (b & 1)res = res * a; res%=mod; a = a * a; a%=mod; }return res; }
//ll p(ll a, ll b) { ll res = 1; for (; b; b >>= 1) { if (b & 1)res = res * a;a = a * a; }return res; }

ll fact[300000];
void pre() {
    fact[0] = 1;
    loop(i,1,300000) fact[i] = (i*fact[i-1])%MOD;
}

bool mysort(const pair<ll,ll>& a, const pair<ll,ll>& b) {
    if(a.first == b.first) return(a.second < b.second);
    return(a.first < b.first);
}

ll mdist(pair<ll,ll> a, pair<ll,ll> b) {
    ll ans = abs(a.first - b.first) + abs(a.second - b.second);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* code */
    double a,b,h,m; cin >> a >> b >> h >> m;
    double t = 60* h + m;
    double pi = 3.14159265359;
    double vel = (11.0/12.0) * (pi / 30);
    double dist = a*a + b*b - 2 * a * b * cos(vel*t);
    dist = sqrt(dist);
    cout << fixed << setprecision(12) << dist << "\n";
    /* end code */
}