#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int ctoi(char c){
    switch (c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
    }
}

int main(){
    string S;
    cin >> S;
    ll len = S.size();
    vector<ll> dp(2019, 0);
    ll prev = 0;
    ll num = 1;
    dp[0]++;
    for (ll i = len - 1; i >= 0; i--){
        dp[(prev + num * ctoi(S[i])) % 2019]++;
        prev = (prev + num * ctoi(S[i])) % 2019;
        num = (num * 10) % 2019;
    }
    ll ans = 0;
    rep(i,2019){
        ans += (dp[i]) * (dp[i] - 1) / 2;
    }
    cout << ans << endl;
}