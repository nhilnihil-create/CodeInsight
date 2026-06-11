#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//繰り返し二乗法
ll EX(ll x,ll n){
    if(n == 0) return 1;
    else if(n%2 == 1) return EX(x,n-1)*x%mod;
    else return EX(x*x%mod,n/2)%mod;
}

vector<bool> prime_flag;
//エストラテネスのなんとか
void flag_prime(ll max){
    if(max +1 > prime_flag.size()) prime_flag.resize(max+1,true);
    prime_flag[0] = false;
    prime_flag[1] = false;
    for(int i = 2; i*i < max+1; i++){
        if(prime_flag[i]){
            for(int j = 2; i*j < max+1; j++) prime_flag[i*j] = false;
        }
    }
}

vector<int> prime_num;
void num_prime(int max){
    for(int i = 0; i < max+1; i++){
        if(prime_flag[i]) prime_num.push_back(i);
    }
}

int main(){
    ll n,k;
    cin >> n >> k;
    map<ll,ll> mp;
    flag_prime(k+1);
    num_prime(k+1);
    for(int i = 1; i <= k; i++){
        mp[i] = EX(k/i,n);
    }
    ll ans = 0;
    for(int i = k; i >= 1; i--){
        for(int j = i*2; j <= k; j += i){
            mp[i] += -mp[j];
        }
    }
    for(int i = 1; i <= k; i++){
        ans += mp[i]*i;
        ans %= mod;
    }
    cout << (ans+mod)%mod << endl;
    return 0;
}