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

struct primes{

    vector<bool> flag;
    void flag_prime(ll max){
        if(max +1 > flag.size()) flag.resize(max+1,true);
        flag[0] = false;
        flag[1] = false;
        for(int i = 2; i*i < max+1; i++){
            if(flag[i]){
                for(int j = 2; i*j < max+1; j++) flag[i*j] = false;
            }
        }
    }

    vector<int> num;
    void num_prime(int max){
        for(int i = 0; i < max+1; i++){
            if(flag[i]) num.push_back(i);
        }
    }

};

int main(){
    ll n,k;
    cin >> n >> k;
    map<ll,ll> mp;
    primes prime;
    prime.flag_prime(k+1);
    prime.num_prime(k+1);
    for(int i = 1; i <= k; i++){
        mp[i] = EX(k/i,n);
    }
    ll ans = 0;
    for(auto p:prime.num){
        for(int i = p; i <= k; i += p){
            mp[i/p] -= mp[i];
        }
    }
    for(int i = 1; i <= k; i++){
        ans += mp[i]*i;
        ans %= mod;
    }
    cout << (ans+mod)%mod << endl;
    return 0;
}