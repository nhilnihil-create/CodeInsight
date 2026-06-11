#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

bool is_prime(long long N){
    if (N == 1) return false;
    for (long long i = 2;i * i <= N;i++){
        if (N % i == 0) return false;
    }
    return true;
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////
long long dp[100010][13];
int main(){
    string s;
    cin >> s;
    
    dp[0][0] = 1;
    for (int i = 0;i < s.size();i++){
        for (int j = 0;j < 13;j++){
            if (s[i] == '?'){
                for (int k = 0;k < 10;k++){
                    dp[i+1][(j*10 + k)%13] += dp[i][j]%mod;
                }
            }
            else {
                int k = s[i] - '0';
                dp[i+1][(j*10+k)%13] += dp[i][j]%mod;
            }
        }
    }
    if (dp[s.size()][5] >= 1e9 + 7){
        dp[s.size()][5] -= mod;
        dp[s.size()][5] %= mod;
    }
    cout << dp[s.size()][5] << endl;
}