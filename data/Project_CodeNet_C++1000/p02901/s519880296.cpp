#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);
int main(){
    int n,m;cin>>n>>m;
    vector<P>as(m);
    rep(i,m){
        int a,b;cin>>a>>b;
        int x =0;
        rep(i,b){
            int y;cin>>y;
            y--;
            x|=1<<y;
        }
        as[i]={x,a};
    }
    vl dp(1<<n+1,INFL);
    dp[0]=0;
    rep(bit,1<<n){
        rep(i,m){
            dp[bit|as[i].first]=min(dp[bit|as[i].first],dp[bit]+as[i].second);
        }
    }
    if(dp[(1<<n)-1]==INFL)cout<<-1<<endl;
    else
    {
         cout<<dp[(1<<n)-1]<<endl;
    }
    
}