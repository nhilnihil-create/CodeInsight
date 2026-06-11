#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = pow(10,9)+7;

ll pow_mod(ll p,ll n){
    if(n==1){
        return p%N;
    }
    if(n%2==0){
        return (pow_mod(p, n/2)*pow_mod(p, n/2))%N;
    }
    else{
        return(pow_mod(p, (n-1)/2) * pow_mod(p, (n+1)/2)) %N;
    }
}

ll combi_mod(ll n, ll k){
    ll up=1;
    ll down =1;
    for(ll i=0; i<k; i++){
        up = (up*(n-i))%N;
    }
    for(ll i=1; i<=k; i++){
        down = (down*i)%N;
    }
    ll ans;
    ans = (up*pow_mod(down, N-2))%N;
    return ans;
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans=1;
    ans = pow_mod(2, n);
    ans--;
    ans -= combi_mod(n,a) + combi_mod(n,b);
    while(ans<0){
        ans += N;
    }
    cout << ans%N << endl;
}
