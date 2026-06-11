#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n;
    cin>>n;
    V<int> ind(n+1,0);
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        ind[a]=i;
    }
    set<int> s;
    V<ll> L(2),R(2); 
    int pos=0;
    ll a,b,c,d;
    ll ans=0;
    for(ll x=n;x>=1;x--){
        s.insert(ind[x]);
        L[0]=L[1]=-1;
        R[0]=R[1]=n;
        auto ite=s.find(ind[x]);
        pos=1;
        while(pos>=0&&ite!=s.begin()){
        ite--;
        L[pos--]=*ite;
        }
        ite=s.find(ind[x]);
        ite++;pos=0;
        while(pos<2&&ite!=s.end()){
            R[pos++]=*ite;
            if(pos!=2)ite++;
        }
        a=ind[x]-L[1];
        b=R[0]-ind[x];
        c=L[1]-L[0];
        d=R[1]-R[0];
        ans+=(a*d+b*c)*x;
    }
    cout<<ans<<"\n";
}