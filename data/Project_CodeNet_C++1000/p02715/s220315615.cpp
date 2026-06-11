#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=1000000007;

ll fast_pw(ll x, ll y) {
    ll sol=1;
    while(y>0) {
        if (y%2==1) sol=(sol*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return sol;
}

ll dp[100005];

int main() {
    int n,k;
    ll sol=0;
    cin >> n >> k;
    for (int i=k;i>=1;i--) {
        dp[i]=fast_pw(k/i,n);
        for (int j=i*2;j<=k;j+=i) {
            dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
    }
    for (int i=1;i<=k;i++) sol=(sol+i*dp[i])%mod;
    cout << sol;
}

