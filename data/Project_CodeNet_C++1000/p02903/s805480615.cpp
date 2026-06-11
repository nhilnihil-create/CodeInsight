#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<int>>;
using dou =long double;
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define res resize
#define as assign
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
 
typedef long long ll;
const int INF = 2000000000;
const ll INF64 = 9223372036854775806ll;
const int mod = 1000000007ll;
const ll  MOD = 1000000007LL;
//-0.4620981203755741
int main(){
    int h,w;
    std::cin >> h>>w;
    vvector(v,int,h,w,0);
    int a,b;
    std::cin >> a>>b;
    //a--;b--;
    
    reprep(i,j,h,w){
        bool aa=0,bb=0;
        if(a>j)aa=1;
        if(b>i)bb=1;
        if(aa^bb)v[i][j]=0;
        else v[i][j]=1;
    }
    rep(i,h){
        rep(j,w)std::cout << v[i][j] ;
        std::cout  << std::endl;
    }
}