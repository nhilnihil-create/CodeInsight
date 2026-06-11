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

int main(){
    ll mod = 1000000007;
    ll n, m;
    cin >> n >> m;
    ll a[n];
    fill(a, a + n, 0);
    rep(i, m){
        ll b;
        cin >> b;
        a[b] = 1;
    }
    ll dp[n+1];
    dp[0] = 1;
    if(a[1] == 1){
        dp[1] = 0;
    }else{
        dp[1] = 1;
    }
    for (ll i = 2; i <= n; i++){
        if(a[i] == 1) dp[i] = 0;
        else {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= mod;
        }        
    }
    cout << dp[n] << endl;
}