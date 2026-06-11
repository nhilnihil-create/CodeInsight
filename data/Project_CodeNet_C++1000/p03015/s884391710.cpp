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
using PPI=pair<P,int>;
//ll const mod=998244353;
ll const mod=1e9+7;
const ll MAX=1000005;
using vi=vector<int>;
using vl=vector<ll>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvl =vector<vector<ll>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////
ll dp[100005][2];

int main(){
    string s;
    cin>>s;
    int n=s.size();
    dp[0][1]=1;
    dp[1][0]=1;
    rep(i,n){
        dp[i+1][0]+=dp[i][0]*3%mod;

        if(s[i]=='1'){
            dp[i+1][0]+=dp[i][1];
            dp[i+1][0]%=mod;
            dp[i+1][1]=dp[i][1]*2%mod;
        }
        if(s[i]=='0'){
            dp[i+1][1]=dp[i][1];
            dp[i+1][1]%=mod;
        }
        if(i==0)dp[1][0]=1;
    }
    ll ans=dp[n][0]+dp[n][1];
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}