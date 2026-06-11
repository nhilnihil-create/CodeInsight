#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define yn(x, ok, ng) cout << ((x)?(ok):(ng)) << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int n,k; cin >> n >> k;
vi a(n); rep(i,n) cin >> a[i];

ll s = 0;
rep(i,n) s += a[i];
vi v;
for(int i = 1; i * i <= s; ++i) {
    if(s % i == 0) {
        v.push_back(i);
        v.push_back(s/i);
    }
    if(i * i == s) v.pop_back();
}
int ans = 1;
for(auto g : v) {
    vi r(n);
    rep(i,n) r[i] = a[i] % g;
    sort(r.begin(), r.end());
    vi sr(n+1), sl(n+1);
    rep(i,n) sl[i+1] = sl[i] + r[i];
    drep(i,n) sr[i] = sr[i+1] + g - r[i];
    rep(i,n+1) {
        if(sl[i] == sr[i] && sl[i] <= k) {
            chmax(ans, g);
            break;
        }
    }
}
cout << ans << endl;
return 0;
}