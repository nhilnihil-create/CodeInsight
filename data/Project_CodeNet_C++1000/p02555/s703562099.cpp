#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    const int MOD = 1000000007;
    int S; cin>> S;
    vector<int> dp(S);
    dp[0] = 0; dp[1] = 0; dp[2] = 1;
    for(int i = 3; i < S; i++){
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
    }
 
    cout<< dp[S - 1] << endl;
}