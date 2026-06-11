#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main()
{
    string a;
    cin >> a;
    for(auto &i : a)i -= '0';
    int n = a.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){                       //何桁目まで見たか
        for(int j = 0; j <= 1; j++){                  //前の状態
            for(int k = 0; k <= (j ? 1 : a[i]); k++){ //遷移の方向

                //1を作り出す遷移は二通り
                if(k){
                    dp[i + 1][j || (k < a[i])] += dp[i][j] * 2;
                }else{
                    dp[i + 1][j || k < (a[i])] += dp[i][j];
                }
                dp[i + 1][j || (k < a[i])] %= mod;
            }
        }
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
}