#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1000005], basis[65];

void add(ll x){
    for(ll i = 63; i >= 0; i--)
        if(x & (1LL << i)){
            if(!basis[i]){
                basis[i] = x;
                return; //tu deu continue era return
            }
            x ^= basis[i]; 
        } // hehe
}

int main(){
    ll n; cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; i++)
        cin >> a[i], sum ^= a[i];
    // sort(a, a+n); reverse(a, a+n);
    // o q aconteceu
    
    // n sei oq vou fazer da minha vida ;-;
    
    for(int i = 0; i <= 60; i++){
        if(sum & (1LL << i)){
            for(int j = 0; j < n; j++){
                if(a[j] & (1LL << i)) a[j] -= (1LL << i);
            }
        }
    }
    
    for(ll i = 0; i < n; i++)
        add(a[i]);

    ll res = 0;
    for(int i = 63; i >= 0; i--){
        if(res & (1LL << i)) continue;
        if(!basis[i]) continue;
        res ^= basis[i];
    }
    // cout << res << " " << sum << endl;
    cout << res + (sum ^ res) << endl;
    return 0;
}