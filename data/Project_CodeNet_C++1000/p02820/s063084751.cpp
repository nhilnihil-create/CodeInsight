#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);


int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,K,R,S,P; cin>>N>>K>>R>>S>>P;
    ll ans=0;
    string s; cin>>s;
    //MOD iについて
    rep(i,K){
        ll tmp=0;
        
        if(sz(s)%K==0) tmp=sz(s)/K;
        else{
            if(i<sz(s)%K) tmp=(sz(s)+K-1)/K;
            else tmp=(sz(s)+K-1)/K-1;
        }
        
        //dp[j][k]:j番目にkを出したときの最高点数
        vector<vector<ll> > dp(tmp+1,vector<ll>(3,0));
        
        rep1(j,tmp){
            if(s[K*(j-1)+i]=='r'){
                chmax(dp[j][2],dp[j-1][0]+P);
                chmax(dp[j][2],dp[j-1][1]+P);
                dp[j][0]=max(dp[j-1][1],dp[j-1][2]);
                dp[j][1]=max(dp[j-1][0],dp[j-1][2]);
            }
            else if(s[K*(j-1)+i]=='s'){
                chmax(dp[j][0],dp[j-1][2]+R);
                chmax(dp[j][0],dp[j-1][1]+R);
                dp[j][1]=max(dp[j-1][0],dp[j-1][2]);
                dp[j][2]=max(dp[j-1][1],dp[j-1][0]);
            }
            else{
                chmax(dp[j][1],dp[j-1][2]+S);
                chmax(dp[j][1],dp[j-1][0]+S);
                dp[j][0]=max(dp[j-1][1],dp[j-1][2]);
                dp[j][2]=max(dp[j-1][1],dp[j-1][0]);
            }
            
        }
        ans+=maxx(dp[tmp][0],dp[tmp][1],dp[tmp][2]);
    }
    cout<<ans<<endl;
}

