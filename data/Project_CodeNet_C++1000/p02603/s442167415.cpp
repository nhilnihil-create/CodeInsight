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

    int n;
    cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i];


    //dp[i]:i日めが始まるタイミングでの所持金(株0)
    vl dp(n+1);
    dp[0]=1000;
    dp[1]=1000;

    //i日めに買ってj日めに売る
    rep(i,n-1){

        ll kabu=dp[i]/a[i];
        ll money=dp[i]%a[i];

        ll m=dp[i];
        repa(j,i+1,n){
            cmax(dp[j+1],max(money+kabu*a[j],m));
            cmax(m,dp[j+1]);
        }
    }

    cout<<dp[n]<<"\n";

    return 0;

}