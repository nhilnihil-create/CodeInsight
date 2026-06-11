#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//nの約数を返す(1を含まない)
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i*i!=n) res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    ll N; cin >> N;
    ll ans = 0;
    ans += divisor(N-1).size() - 1;
    vector<ll> divN = divisor(N);
    for(auto &K : divN){
        if(K == 1) continue;
        ll n = N;
        while(n % K == 0){
            n /= K;
        }
        if(n % K == 1) ans++;
    }
    cout << ans << endl;
}