#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;


const int mod = 1e9+ 7;

int main() {
    string s;
    cin>>s;

    int len = s.size();

    reverse(s.begin(),s.end());

    int dp[110000][13];

    if(s[0]=='?') {
        for(int i=0; i<10; i++){
            dp[0][i] = 1;
        }
        } else {
            int index = s[0]-'0';
            dp[0][index] = 1;
        }

    int num = 1;
    for(int i= 1; i<len; i++){
        num *=10;
        num %=13;

        if(s[i]=='?'){
            rep(j, 10){
                rep(k, 13){
                    int index = (j*num + k)%13;
                    dp[i][index] += dp[i - 1][k];
                    dp[i][index] %=mod;
                }
            }

        }else{
            rep(k,13){
                int j = (s[i]-'0');
                int index = (j*num+k)%13;
                dp[i][index] += dp[i - 1][k];
                dp[i][index] %mod;
            }

        }

    }

    cout<< dp[len -1][5]<<endl;

    return 0;


}