#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
//const ll mod=1e9+7;
const ll MAX=300000;
using vi=vector<int>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////
ll modpow(ll a,ll b){
  ll r=1;
  while(b>0){
    if(b%2==1)(r*=a)%=mod;
    (a*=a)%=mod;
    b/=2;
  }
  return r;
}

int main(){
    
    int n;
    cin>>n;
    vector<ll> d(n);
    int mx=0;
    rep(i,n){
        int a;
        cin>>a;
        if(i==0&&a!=0){
            cout<<0<<endl;
            return 0;
        }
        d[a]++;
        chmax(mx,a);
    }
    if(d[0]>1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    
    for(int i=mx-1;i>=0;i--){
        if(d[i]==0){
            cout<<0<<endl;
            return 0;
        }
        ans*=modpow(d[i],d[i+1]);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}