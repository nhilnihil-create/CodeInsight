#include <bits/stdc++.h>
 
using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<PII>
#define LD long double

int s;
int mod(int n,int m){
    n%=m;
    n=(n < 0) ? n + m : n;
    return n;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);
    cin >> s;
    int m = (int)pow(10,9)+7;
    VI dp(s+10,0);
    dp[3]=1,dp[4]=1,dp[5]=1;
    FOR(i,5,s){
        dp[i+1] = mod(dp[i]+dp[i-2],m);
    }
    cout << dp[s] << endl;
}
