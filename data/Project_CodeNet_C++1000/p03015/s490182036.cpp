#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

ll dp[100005];
ll dpl[100005];
const ll MOD = 1e9+7;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    dp[0]=1;
    dpl[0]=2;
    REP(i,n-1){
        if(s[i]-'0'==1){
            dp[i]=(dp[i-1]*3+dpl[i-1])%MOD;
            dpl[i]=(dpl[i-1]*2)%MOD;
        }else{
            dp[i]=(dp[i-1]*3)%MOD;
            dpl[i]=dpl[i-1];
        }
    }

    cout<<(dp[n-1]+dpl[n-1])%MOD<<endl;
    return 0;
}