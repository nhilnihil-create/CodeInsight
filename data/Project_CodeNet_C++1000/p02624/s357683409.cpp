#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    ll n;
    cin>>n;
    vector<ll> prime(n+1,0),divisor(n+1,0);
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            prime[j] += 1;
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans += prime[i]*i;
    }
    cout<<ans<<endl;
}