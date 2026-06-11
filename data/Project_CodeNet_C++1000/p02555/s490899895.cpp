typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
ll maxl(ll a, ll b){ return ((a<b)?b:a);}
ll minl(ll a, ll b){ return ((a>b)?b:a);}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin >> s;
    vector<ll> dp(s+1,0);
    vector<ll> prefix(s+1,0);
    dp[0] = 1;
    prefix[0] = 1;
    int M = 1e9 + 7;
    for (int i=3;i<=s;i++){
        dp[i] = (dp[i] + prefix[i-3])%M;
        prefix[i-2] = (prefix[i-3] + dp[i-2])%M;
    }
    cout << dp[s] << "\n";
}

