#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     string s;
     cin >> s;
     int n = s.length();
     vector< vector<int> > dp(n+1,vector<int>(13));
     dp[0][0] = 1;
     for(int i = 0;i<n;i++){
        for(int j = 0;j<13;j++){
            if(s[i]=='?'){
                for(int k = 0;k<10;k++) {
                        dp[i+1][(j*10+k)%13] += dp[i][j];
                        dp[i+1][(j*10+k)%13] %= mod;
            }}
            else{
                        int k = s[i] - '0';
                        dp[i+1][(j*10+k)%13] += dp[i][j];
                        dp[i+1][(j*10+k)%13] %= mod;
            }
     }}
     cout << dp[n][5];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}