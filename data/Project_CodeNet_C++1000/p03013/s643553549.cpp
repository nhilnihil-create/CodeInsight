#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){return (a % b)? gcd(b, a % b) : b;}
template<typename T> T lcm(T a, T b){return a * b / gcd(a, b);}

void solve_129C(){
    int n, m;
    cin >> n >> m;
    vector<bool> a(n+1, true);
    REP(i,m){
        int x;
        cin >> x;
        a[x] = false;
    }

    vector<int> dp(n+10, 0);
    dp[0] = 1;
    
    if(a[1]) dp[1] = 1;
    for(int i = 2; i < n + 5; i++){
        if(a[i]) dp[i] += dp[i-1] % MOD;
        if(a[i]) dp[i] += dp[i-2] % MOD;
    }
    
    cout << dp[n] % MOD << endl;
}

int main(void){
    solve_129C();
    
    return 0;
}