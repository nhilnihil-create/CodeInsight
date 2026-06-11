#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll dp[100005][13];

int main(){
    string s;
    cin >> s;
    ll n=s.size();
    dp[0][0]=1;
    ll res;
    for(ll i=0;i<n;i++){
        ll c;
        if(s[i]=='?') c=-1;
        else c=s[i]-'0';
        for(ll j=0;j<10;j++){
            if(c!=-1&&c!=j) continue;
            for(ll k=0;k<13;k++){
                dp[i+1][(k*10+j)%13]+=dp[i][k];
            }
        }
        for(ll j=0;j<13;j++) dp[i+1][j]%=mod;
    }
    res=dp[n][5];
    cout << res << endl;
    return 0;
}
