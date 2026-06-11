#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++){
        for (int k = 0; k < B.size(); k++){
            for (int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
    ll n, m;
    cin >> n >> m;
    ll s[n], t[m];
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];
    ll dp[n+1][m+1];
    dp[0][0] = 1;
    rep(i, n)dp[i+1][0] = 1;
    rep(i, m)dp[0][i+1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod;
            }
            dp[i][j] %= mod;
        }
    }
    // rep(i, n + 1){
    //     rep(j, m + 1){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    cout << dp[n][m] << endl;    
}