#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N=pow(10,9)+7;

ll mod_pow(ll a, ll n){
    ll ans;
    if(n==0) return 1;
    else{
        if(n%2==0){
            ans = (mod_pow(a,n/2) * mod_pow(a,n/2))%N;
            return ans;
        }
        else{
            ans = (mod_pow(a,(n-1)/2) * mod_pow(a,(n-1)/2))%N;
            ans = (ans * a) %N;
            return ans;
        }
    }
}

ll combi(ll n, ll k){
    ll up=1;
    ll down=1;
    for(ll i=0; i<k; i++){
        up = (up * (n-i))%N;
    }
    for(ll i=1; i<=k; i++){
        down = (down*i)%N;
    }
    ll ans = mod_pow(down, N-2);
    return (ans * up)%N;
}


int main(){
    ll n, k;
    cin >> n >> k;
    for(ll i=1; i<=k; i++){
        ll ans;
        ans = combi(n-k+1, i);
        ans = (ans* combi(k-1,i-1))%N;
        cout << ans << endl; 
    }
}
