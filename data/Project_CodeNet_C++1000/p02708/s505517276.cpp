#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const ll mod = 1e9 + 7;
int main(){
ll n,k;
cin >> n >> k;
vector<ll>pre(n+10);
vector<ll>suf(n+10);
ll sum = 0;
for(ll i = 0;i<=n+1;i++){
     sum += i;
     pre[i] = sum;
}
sum = 0;
for(ll i = n+1;i>=0;i--){
    sum += i;
    suf[n+2-i] = sum;
}
ll ans = 0;
for(ll i = k;i<=n+1;i++){
    ans += (suf[i] - pre[i]+1ll)%mod;
    ans %= mod;
}
cout << ans;
return 0;
}