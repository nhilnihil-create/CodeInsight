#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i = 1LL; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            ll j = n / i;
            if(i != j)res.push_back(j);
        }
    }
    std::sort(res.begin(),res.end());
    return res;
}

ll calc(ll n, ll k) {

    while(n >= k) {
        if(n % k)n %= k;
        else n /= k;
    }
    return n;
}

int main()
{
    ll n;
    cin >> n;
    int cnt = divisor(n - 1).size() - 1;
    vector<ll> dis = divisor(n);
    //cerr << "yay" << endl;
    for(auto i : dis) {
        if(i == 1)continue;
        if(calc(n, i) == 1)cnt++;
    }
    cout << cnt << endl;

}