#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n,k,r,s,p;
    string t;
    cin>>n>>k>>r>>s>>p>>t;
    vvi dp(n+1,vi(2));
    dp[0][0]=0;
    dp[0][1]=0;
    rep(i,n){
        lli win;
        if(t[i]=='r') win=p;
        else if(t[i]=='s') win=r;
        else win=s;
        dp[i+1][1]=max(dp[i][1],dp[i][0]);
        if(i>=k&&t[i-k]==t[i]&&dp[i-k+1][0]==max(dp[i-k][0],dp[i-k][1])+win){
            dp[i+1][0]=max(dp[i][0],dp[i][1]);
        }
        else{
            dp[i+1][0]=max(dp[i][0],dp[i][1])+win;
        }

    }
    out(max(dp[n][0],dp[n][1]));
}   