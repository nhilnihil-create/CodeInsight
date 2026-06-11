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
#define rep(i, n) for(ll i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

ll dp[100005][13];

int main(){
    string s;
    cin >> s;
    rep(i, 100005)rep(j, 13) dp[i][j] = 0;
    if (s[0] == '?'){
        rep(i, 10) dp[0][i] = 1;
    }else{
        rep(i, 13){
            if(i == s[0] - '0') dp[0][i] = 1;
        }
    }
    
    for (ll i = 1; i < s.size(); i++){
        if(s[i] == '?'){
            rep(j, 13){
                rep(k, 10){
                    ll num = (j * 10 + k) % 13;
                    dp[i][num] += dp[i-1][j];
                    dp[i][num] %= mod;
                }
            }
        }else{
            rep(j, 13){
                ll num = (j * 10 + (s[i] - '0')) % 13;
                // if(i == 2){
                //     cout << num << endl;
                // }
                
                dp[i][num] += dp[i-1][j];
                dp[i][num] %= mod;
            }
        }
    }

    // rep(i, s.size()){
    //     rep(j, 13){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    cout << dp[s.size()-1][5] << endl;
    
}