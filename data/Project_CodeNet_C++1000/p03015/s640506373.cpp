#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int mod = 1000000007;
int dp[100005][2];//0->same 1->smaller

int main(){
    string s; cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    rep(i,n){
        //i桁目でa+b=0
        if(s[i] == '0'){
            (dp[i+1][0] += dp[i][0]) %= mod;
            (dp[i+1][1] += dp[i][1]) %= mod;
        }else{
            (dp[i+1][1] += (dp[i][0] + dp[i][1]) % mod) %= mod;
        }
        //i桁目でa+b=1
        if(s[i] == '0'){
            (dp[i+1][1] += dp[i][1]*2 % mod) %= mod;//aとbどちらにbitが立っているか
        }else{
            (dp[i+1][0] += dp[i][0]*2 % mod) %= mod;
            (dp[i+1][1] += dp[i][1]*2 % mod) %= mod;
        }
    }
    int ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << endl;
    return 0;
}