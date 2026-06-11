#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream& operator>>(istream& is,vector<T>& a){
    for(int i=0;i<a.size();i++)is>>a[i];
    return is;
}
template<typename T,typename U>
istream& operator>>(istream& is,pair<T,U>& p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
    for(int i=0;i<a.size();i++){
        os<<a[i]<<((i+1!=a.size())?" ":"");
    }
    return os;
}
template<typename T,typename U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
    os<<p.first<<" "<<p.second;
    return os;
}

// struct hishimochi{
//     hishimochi(){
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//     }
// };
// hishimochi Hishimochi;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pll=pair<long long,long long>;
using vl=vector<long long>;
using vvl=vector<vector<long long>>;
using vvvl=vector<vector<vector<long long>>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
using vs=vector<string>;
using vb=vector<bool>;
using vvb=vector<vector<bool>>;
using vp=vector<pair<long long,long long>>;
using Lqueue=priority_queue<long long>;
using Squeue=priority_queue<long long,vector<long long>,greater<long long>>;

const int MOD1=1000000007;
const int MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const long long INF=2305843009213693951;
const long double eps=0.0000000001;
const int dx[]={0,1,0,-1,1,-1,1,-1};
const int dy[]={1,0,-1,0,1,1,-1,-1};

#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(int _=0;_<(n);_++)
#define rep2(i,n) for(int i=0;i<(n);i++)
#define rep3(i,s,n) for(long long i=(s);i<(n);i++)
#define rep(...) overload3(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define bitrep1(n) for(int _=0;_<(1LL<<(n));_++)
#define bitrep2(i,n) for(int i=0;i<(1LL<<(n));i++)
#define bitrep3(i,s,n) for(int i=(s);i<(1LL<<(n));i++)
#define bitrep(...) overload3(__VA_ARGS__,bitrep3,bitrep2,bitrep1)(__VA_ARGS__)

#define rbf(a,x) for(auto& a:x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define bitcheck(bit,i) (bit)&(1LL<<(i))
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Sume(x) accumulate((x).begin(),(x).end,0LL)
#define SIZE(x) ((long long)(x).size())
#define Lin(s) getline(cin,(s))

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define eb emplace_back

void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
inline long long cutup(long long a,long long b){return (a+b-1)/b;}
inline long long popcnt(long long a){return __builtin_popcountll(a);}
template<class T,class U> auto max(T a,U b){return a>b?a:b;}
template<class T,class U> auto min(T a,U b){return a<b?a:b;}
template<class T,class U> inline bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template<class T,class U> inline bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}

struct edge{long long to,cost;};
struct edge2{long long from,to,cost;};

struct UnionFind{
    vector<int> par;
    UnionFind(int n):par(n,-1){}

    int root(int x){
        if(par[x]<0)return x;
        else return par[x]=root(par[x]);
    }

    bool issame(int x,int y){
        return root(x)==root(y);
    }

    bool merge(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};

signed main(){
    ll n,m;
    cin>>n>>m;
    UnionFind UF(n);
    rep(m){
        ll a,b;
        cin>>a>>b;
        UF.merge(a-1,b-1);
    }
    ll res=0;
    rep(i,n){
        chmax(res,UF.size(i));
    }
    cout<<res<<"\n";
}