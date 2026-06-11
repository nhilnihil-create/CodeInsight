#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define fi first
#define se second
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
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

ll N,D,A;
cin >> N >> D >> A;

set<ll> v;
map<ll, ll> hp;
map<ll, ll> add;
D *= 2;
rep(i,N) {
    ll x,h;
    cin >> x >> h;
    v.insert(x);
    v.insert(x + D);
    hp[x] = h;
}

ll ans = 0;
ll cur = 0; // imos

for(auto x : v) {
    ll cnt = (max((ll)0, hp[x] - cur) + A - 1) / A;
    ans += cnt;
    cur += A * cnt;
    add[x + D] = A * cnt;
    cur -= add[x];
}
cout << ans << endl;
return 0;
}