#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << end
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

ll prime_count(ll n){
    map<ll,ll> mp;
    ll res = 1;
    ll x = n;
    for(ll i=2;i*i<=n;i++){
        while(n%i == 0){
            n/=i;
            mp[i]++;
        }
    }
    if(n != 1)mp[n]++;
    for(auto a:mp) res*=a.second+1;
    return res-1;//約数の個数から1を引く
}
ll factor_count(ll n){
    vector<ll> a;
    ll res = 0;
    for(ll i=2;i*i<=n;i++){
        if (n % i == 0) {
            a.push_back(i);
            ll j = n / i;
            if (j != i) a.push_back(j);
        }
    }
    //debug(a);
    for(auto b:a){
        ll N = n;
        while(N % b == 0) N/=b;
        if(N%b==1)res++;
    }
    return res;
}
signed main()
{   
    gearup;
    ll n; cin >> n;
    //まずk=n-1の素因数を求める
    //素数なら一個
    ll res = prime_count(n-1);
    res += factor_count(n);
    cout << res+1 << endl;
}
