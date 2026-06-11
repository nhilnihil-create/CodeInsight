#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=max(x,a)
#define chmin(x,a) x=min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
#define greater greater<int>()
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Edge=pair<int,ll>;
using Graph=vector<vector<bool> >;//ll or Edge
using Edge=pair<int,ll>;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// g++ -o a a.cpp -Wall -lm -std=c++17
int main(){
    ll x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    vector<P>S;
    rep(i,a){
        ll t;cin>>t;
        S.push_back(P(t,0));
    }
    rep(i,b){
        ll t;cin>>t;
        S.push_back(P(t,1));
    }
    rep(i,c){
        ll t;cin>>t;
        S.push_back(P(t,2));
    }
    sort(ALL(S));
    reverse(ALL(S));
    ll sum=0;
    ll ans=0;
    ll lim=x+y;
    for(auto v:S){
        if(v.se==0 && x>0){x--;sum++;ans+=v.fi;}
        else if(v.se==1 && y>0){y--;sum++;ans+=v.fi;}
        else if(v.se==2 && sum<lim){sum++;ans+=v.fi;}
        if(sum==lim)break;
    }
    cout<<ans<<endl;

}