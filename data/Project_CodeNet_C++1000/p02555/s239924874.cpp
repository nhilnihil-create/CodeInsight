#include<iostream>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll dp[2005];

int main(){
    ll n; cin>>n;
    dp[0] = 1;
    for(int i = 3; i <= n; i++){
        for(int j = i - 3; j >= 0; j--){
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    cout<<dp[n]<<endl;
}
