#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
using Graph = vector<VecP>;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m); (i) > (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define R cin>>
#define i64 unsigned long long
#define repr(i, n) REPR(i, n, 0)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define in(a) insert(a)
#define P(p) cout<<(p)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SORT(a) sort((a).begin(), (a).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
void sonic(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll mod = 1e9+7;
//const ll MOD = 998244353;
const ld PI = acos(-1);
const ld EPS = 1e-11;
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<typename T> void co(T e){cout << e << "\n";}
template<typename T> void co(const vector<T>& v){for(const auto& e : v)
    { cout << e << " "; } cout << "\n";}
ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0) return a;
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}
bool prime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0)return false;
    }
    return n != 1;
}


int pow(ll x, ll y, ll mod){
    ll ret=1;
    for(;y;y>>=1,x=1ll*x*x%mod){
        if(y&1) ret=1ll*ret*x%mod;
    }
    return ret;
}

int main() {
    sonic();
    int n;
    R n;
    i64 total, l, r, i, t, next, prev, cnt=0;
    bool flg=true;
    priority_queue<pii> pq;
    vi A(n), B(n);
    rep(i, n)R A[i];
    rep(i, n){
        R B[i];
        pq.push({B[i], i});
    }
    while(0<pq.size()) {
        i = pq.top().second;
        pq.pop();
        if(B[i]==A[i])continue;
        next = (i + 1 + n) % n;
        prev = (n + i - 1) % n;
        total = B[next] + B[prev];
        t = (B[i] - A[i]) / total;
        cnt += t;
        if(t==0){flg=false;break;}
        B[i] = B[i] - t * total;
        pq.push({B[i], i});
    }
    if(flg)co(cnt);
    else co(-1);
}
