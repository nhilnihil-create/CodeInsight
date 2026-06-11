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

using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
using PPI=pair<P,int>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vl=vector<ll>;
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
const int INF=1e9;
const ll LINF=1e18;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////


int main(){
    int n;
    cin>>n;
    vi a(n+1);
    rep(i,n+1)cin>>a[i];
    
    vl b(n+1);
    
    rep(i,n+1){
        if(i==0){
           b[i]=1-a[i];
        }
        else{
            b[i]=2*b[i-1]-a[i];
            chmin(b[i],LINF);
            
        }
        if(b[i]<0){
                cout<<-1<<endl;
                return 0;
        }
    }
    vl d(n+1);
    d[n]=a[n];
    
    for(int i=n-1;i>=0;i--){
        d[i]=min(b[i]+a[i],d[i+1]+a[i]);
    }
    ll ans=0;
    rep(i,n+1)ans+=d[i];
    cout<<ans<<endl;
}