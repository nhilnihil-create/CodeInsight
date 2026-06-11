#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<pair<ll,int>> soinsuu_bunkai(ll N){

    vector<pair<ll,int>> res;
    ll t = N;
    for(ll i=2;i*i<=N;i++){
        if(t == 1) break;
        if(t % i == 0){
            ll prime = i;
            int cnt = 0;
            while(t % i == 0){
                t /= i;
                cnt++;
            }
            res.push_back(make_pair(prime,cnt));
        }
    }
    if(t != 1)
        res.push_back(make_pair(t,1));
    return res;
}

int main(){

    ll N;
    cin >> N;

    auto primes = soinsuu_bunkai(N);
    int res = 0;
    for(auto p : primes){
        int cnt = 1;
        int t = p.second;
        while(t >= cnt){
            t -= cnt++;
            res++;
        }
    }
    
    cout << res;
    return 0; 
}