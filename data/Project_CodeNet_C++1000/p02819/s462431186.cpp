#include <bits/stdc++.h>
using namespace std;
using ll =long long;

vector<bool> sieve(ll N){
    vector<bool> prime(N+1,true);
    prime[0]=false,prime[1]=false;
    for (ll i = 2; i < N; i++){
        if(!prime[i]) continue;
        for(ll j=i*i;j<=N;j+=i){
            prime[j]=false;
        }
    }
    return prime;
}

int main(){
    ll X; cin>>X;
    vector<bool> prime=sieve(100004);
    for (ll i = X;; i++){
        if(prime[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    
}