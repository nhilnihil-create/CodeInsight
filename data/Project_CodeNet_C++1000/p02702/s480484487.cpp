#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

const int mod = 2019;

int main(){
    string s; cin >> s;
    int n = s.length();

    int dp1[n]; // 10^n mod.mod
    dp1[0] = 1; for(int i=0; i<n-1; i++) dp1[i+1] = (dp1[i]*10)%mod;
    int dp2[n+1]; // Ti mod.mod
    dp2[n] = 0; for(int i=n-1; i>=0; i--) dp2[i] = (dp2[i+1] + (s[i]-'0')*dp1[n-1-i])%mod;

    int count[mod]; 
    rep(i,mod) count[i] = 0;
    rep(i,n+1) count[dp2[i]]++;

    int ans = 0;
    rep(i,mod){
        ans += count[i]*(count[i]-1)/2;
    }
    cout << ans << endl;
}