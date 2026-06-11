#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<class T> void chmin(T& x, T y){if(x < y) x = y;}
template<class T> void chmax(T& x, T y){if(x > y) x = y;}
const ll mod = 1e9 + 7;
int N, M;
int S[2010];
int T[2010];
ll dp[2010];
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> S[i];
    for(int i = 1; i <= M; i++) cin >> T[i];
    for(int i = 1; i <= N; i++){
        ll sum = 0;
        for(int j = 1; j <= M; j++){
            ll s = dp[j];
            if(S[i] == T[j]){
                dp[j] += sum + 1;
                dp[j] %= mod;
            }
            sum += s;
            sum %= mod;
        }
    }
    ll res = 1;
    for(int i = 1; i <= M; i++){
        res += dp[i];
        res %= mod;
    }
    cout << res << endl;
    return 0;
}