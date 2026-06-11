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
typedef pair<ll,ll> P;
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
    
    ll N,M; cin>>N>>M;
    //コスト
    vector<ll> A(M+1,0);
    
    //鍵iができる箱
    vector<ll> BOX(M+1,0);
    
    //鍵i
    rep1(i,M){
        ll B; cin>>A[i]>>B;
        
        ll tmp=0;
        //箱x
        rep(j,B){
            ll x; cin>>x;
            //箱1,3なら
            // .....     [3-1][2-1][1-1]
            // ..... 0 0   1    0    1
            tmp += pw2[x-1];
        }
        BOX[i]=tmp;
    }
    
    //dp[i][j]:鍵iまで見てjの状態になる.コスト最小
    vector<vector<ll> > dp(M+1,vector<ll>(pw2[12],INF));
    dp[0][0]=0;
    
    rep1(i,M){
        rep(j,pw2[N]){
            //i-1まで見て状態j
            //鍵i使う
            chmin(dp[i][j|BOX[i]],dp[i-1][j]+A[i]);
            //使わない
            chmin(dp[i][j],dp[i-1][j]);
        }
    }
    
    if(dp[M][pw2[N]-1]==INF) cout<<-1<<endl;
    else cout<<dp[M][pw2[N]-1]<<endl;
}

