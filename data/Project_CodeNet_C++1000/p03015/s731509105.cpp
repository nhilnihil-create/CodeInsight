#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
const int mod=1000000007;
ll dp[100005][2];
int main(){
    string s;cin >> s;
    dp[0][0]=1;
    int n=s.size();
    for(int i=0;i<n;i++){
        {
            if(s[i]=='0'){
                dp[i+1][0]=dp[i][0];
                dp[i+1][1]=dp[i][1];
            }
            else{
                dp[i+1][1]=(dp[i][1]+dp[i][0])%mod;
            }
        }
        {
            if(s[i]=='0'){
                (dp[i+1][1]+=dp[i][1]*2%mod)%=mod;
            }
            else{
                (dp[i+1][0]+=dp[i][0]*2%mod)%=mod;
                (dp[i+1][1]+=dp[i][1]*2%mod)%=mod;
            }
        }
    }
    ll ans=(dp[n][0]+dp[n][1])%mod;
    cout << ans << endl;
    return 0;
}