#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    string S; cin >> S;

    vector<ll> dp(13, 0);
    dp[0] = 1;
    int mul = 1;

    for (int i = S.size()-1; i >= 0; i--){
        vector<ll> nextdp(13, 0);
        
        if (S[i] == '?'){
            for (int k = 0; k < 10; k++){
                for (int j = 0; j < 13; j++){
                    nextdp[(k*mul+j)%13] += dp[j];
                    nextdp[(k*mul+j)%13] %= MOD;
                }
            }
        }
        else{
            int k = (int)(S[i] - '0');
            for (int j = 0; j < 13; j++){
                nextdp[(k*mul+j)%13] += dp[j];
                nextdp[(k*mul+j)%13] %= MOD;
            }
        }

        mul *= 10;
        mul %= 13;
        dp = nextdp;
    }


    cout << dp[5] << endl;    
}