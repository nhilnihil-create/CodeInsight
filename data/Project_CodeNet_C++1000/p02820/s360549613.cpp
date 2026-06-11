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
ll const mod=998244353;
//ll const mod=1e9+7;
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
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}


//////////////////////////////////////


int main(){
    int n,k;
    cin>>n>>k;
    int r,c,p;
    cin>>r>>c>>p;
    map<int,int>mp;
    mp['r'-'a']=p;
    mp['s'-'a']=r;
    mp['p'-'a']=c;
    string s;
    cin>>s;
    ll ans=0;
    rep(i,k){
      vi dp(2),tmp(2),p;
      for(int j=i;j<n;j+=k){
        p.push_back(s[j]-'a');
      }
      int n=p.size();
      
      rep(j,n){
        swap(dp,tmp);
        if(j==0){
          dp[1]=mp[p[j]];
          continue;
        }
        if(p[j]==p[j-1]){
          dp[1]=tmp[0]+mp[p[j]];
        }
        else{
          dp[1]=max(tmp[0],tmp[1])+mp[p[j]];
        }
        dp[0]=max(tmp[0],tmp[1]);
        
      }
      ans+=max(dp[0],dp[1]);
    }
    cout<<ans<<endl;

    return 0;
}