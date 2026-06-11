#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i=x;i<(int)n;i++)
#define rep(i,n) REP(i,0,n)
#define sp(p) cout<<setprecision(16)<<fixed<<p<<endl;
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(rall(a))
#define UNIQ(a) unique(all(a))
#define UNIQNUM(a) UNIQ(a)-a.begin()
#define UNIQIT(a) a.erase(UNIQ(a), a.end());
#define VOUT(v,i) rep(i,v.size())cout<<v[i]<<(i==v.size()-1?"\n":" ");
#define vout(v) VOUT(v,z);
#define vdbg(v,i) cout<<#v<<": ";for(int i=0;i<(int)v.size();i++){cout<<v[i]<<" ";}cout<<"\n";
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define vsum(v) accumulate(all(v), 0LL)
#define MOUT(m,r,c) rep(i,r){rep(j,c){cout<<m[i][j]<<" ";}cout<<endl;}
#define mout(m) MOUT(m,m.size(),m[0].size())
#define debg(a) cout<<#a<<": "<<a<<endl;
#define show(a) for(cont &y:a){for(cont &x:y){cout<<x<<" ";}cout<<endl;}
#define digit(a) to_string(a).length();
template<class T>inline int out(const T &t){ print(t); putchar('\n'); return 0; }
// template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
// template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
bool is_palindrome(string s){return s == string(s.rbegin(),s.rend());}
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef vector<ll> V;
typedef vector<vector<ll>> VV;
// const long long MOD=1000000007;
const long long INF = 1e18;
#define EPS (1e-7)
#define PI (acos(-1))
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) { a = b; return true; }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) { a = b; return true; }
    return false;
}



int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long H;
    scanf("%lld",&H);
    long long M;
    scanf("%lld",&M);

    double angh = 360*H/12.0+30*M/60.0;
    double angm = 360*M/60.0;
    double angd = min(abs(angh-angm), 360-abs(angh-angm));
    double rad = angd*PI/180.0;
    // debg(angh)debg(angm)debg(angd)debg(rad)
    double c = A*A + B*B - 2*A*B*cos(rad);
    sp(sqrt(c))

    return 0;
}
