#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            ll j = n / i;
            if(i != j)res.push_back(j);
        }
    }
    sort(res.begin(),res.end(), greater<ll>());
    return res;
}


int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> as(n);
    for(ll i = 0; i < n; i++)cin >> as[i];
    ll sum = accumulate(as.begin(), as.end(), 0);
    vector<ll> div = divisor(sum);


    for(auto D : div) 
    {
        vector<ll> b = as;
        for(auto &i : b)i %= D;
        sort(b.begin(), b.end());


        for(ll i = 0; i <= n; i++) {
            ll up = 0, dw = 0;

            for(ll j = 0; j < i; j++)up += b[j];
            for(ll j = i; j < n; j++)dw += D - b[j];
            if(max(up, dw) <= k) {
                cout << D << endl;
                return 0;
            }

        }
    }
    cout << 1 << endl;
}