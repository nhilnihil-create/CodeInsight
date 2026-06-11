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
//#define vvector(name,typ,m,n)vector<vector<typ> > name(m,vector<typ> (n))
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

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
//typedef long long T;
ll ceil(ll a,ll b){
    return ((a+b-1)/b);
}
const int INF = 2000000000;
const ll INF64 = 9223372036854775807ll;
const ll MOD = 1000000007ll;
const dou pi=3.141592653589793;
//mapは、if関数などで覗いただけで構成されるので注意しよう！
//std::vector<vector<int>> g;


//std::vector<std::set<int>> g;
std::map<double, pair<double,double>> m;
pair<double,double>rot(pair<double,double>a,pair<double,double>b){
    double dx=b.fi-a.fi,dy=b.se-a.se;
    double d=dx*cos(pi/3)-dy*sin(pi/3);
    double dd=dx*sin(pi/3)+dy*cos(pi/3);
  //  return mp(d,dd);
    return mp(a.fi+d,dd+a.se);
}
void koch(int n){
    if(n==0)return;
    std::map<double, pair<double,double>> dm(m);
  //  std::cout << m.size() << std::endl;
    double r=-1,rx,ry;
    erep(i,dm){
      //  std::cout << 123 << std::endl;
        double t=i.fi;
        double x=i.se.fi;
        double y=i.se.se;
        if(r==-1){
            r=t,rx=x,ry=y;
            continue;
        }
        double dt=(t-r)/4;
        double dx=x-rx,dy=y-ry;
        m[r+dt]=mp(rx+dx/3,ry+dy/3);
        m[r+dt*3]=mp(rx+dx*2/3,ry+dy*2/3);
        m[r+dt*2]=rot(m[r+dt],m[r+dt*3]);
        r=t,rx=x,ry=y;
    }
    koch(n-1);
}

int main(){
    int n;
    std::cin >> n;

    m[0]=mp(0,0);
    m[1]=mp(100,0);
    koch(n);
    erep(i,m){
        std::cout << keta(10)<<i.se.fi<<' '<<i.se.se << std::endl;
    }
}
