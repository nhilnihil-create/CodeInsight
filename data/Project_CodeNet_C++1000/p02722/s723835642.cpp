#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++){
        if(n % i != 0) continue;
        res.push_back(i);
        if(i * i != n)
            res.push_back(n / i);
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll cnt = 0;
    for(auto x : divisor(n)){
        if(x == 1) continue;
        ll cp = n;
        while(cp % x == 0)
            cp /= x;
        if(cp % x == 1)
            cnt++;
    }
    cnt += divisor(n-1).size() - 1;
    cout << cnt << endl;
    return 0;
}