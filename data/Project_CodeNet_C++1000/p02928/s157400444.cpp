#include <bits/stdc++.h>
using namespace std;

//using Graph = vector<vector<edge>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define query int qq;std::cin >> qq;rep(qqq,qq)
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout <<"Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define ssum(a) accumulate(a,0ll) 
#define gre(n) greater<n>()

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
//typedef long long T;
const int INF = 1000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 1000000007ll;
const dou pi=3.141592653589793;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll moddiv(ll a,ll b){
    a%=MOD;
    return a*modinv(b,MOD)%MOD;
}
int main(){
    ll n,k;
    std::cin >> n>>k;
    VEC(ll,a,n);
    std::vector<ll> c1(n),c2(n);
    ll ans=0;
    rep(i,n){
        rep(j,n){
            if(a[i]>a[j]){
                c1[i]++;
                if(i<j)c2[i]++;
            }
        }
    }

    rep(i,n){
        ll d=((2*c2[i]+(k-1)*c1[i]))%MOD;
        
        d*=k;
        //d/=2;
        d=moddiv(d,2ll);
        ans+=d;
        //ans+=k*((2*c2[i]+((k-1)*c1[i])))/2;
        ans%=MOD;
    }
    
    std::cout << ans << std::endl;
 //   erep(i,c2)std::cout << i << std::endl;
}
