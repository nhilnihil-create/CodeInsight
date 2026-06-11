#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=n-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define vc vector

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){

    string s;
    cin>>s;
    int n=s.length();

    vvi dp(n,vi(2));
    dp[0][0]=1;
    if(s[0]!=s[1])dp[1][0]=2;
    else dp[1][0]=1;
    dp[1][1]=1;

    repa(i,2,n){
        dp[i][0]=dp[i-1][1]+1;
        if(s[i]!=s[i-1])cmax(dp[i][0],dp[i-1][0]+1);

        dp[i][1]=max(dp[i-2][1],dp[i-2][0])+1;
    }

    cout<<max(dp[n-1][0],dp[n-1][1])<<"\n";

    return 0;

}