#include<bits/stdc++.h>
 
typedef long long int ll;
 
using namespace std;
 
#define MOD (ll)1000000007
 
ll arr[1000000];
 
int main(){
 
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll sum = 0;
    for(ll i = 0; i < 60; i++){
        ll oc = 0, zc = 0;
        for(ll j = 0; j < n; j++){
            if(arr[j]%2 == 0){
                zc++;
            }
            else{
                oc++;
            }
            arr[j] /= 2;
        }
        sum = (sum + ((zc * oc) % MOD * ((1ll << i) % MOD)) % MOD) % MOD;


    }
    cout << sum;
}