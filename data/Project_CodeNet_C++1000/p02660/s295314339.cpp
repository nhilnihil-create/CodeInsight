#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n){
    ll x = 1;
    if(n == 0) return 0;
    else {
        while(!(x*(x+1) <= 2*n && 2*n < (x+1)*(x+2))) x++;
    }
    return x;
}

int main(void){
    ll n, ans = 0;
    cin >> n;
    ll m = n;
    vector<vector<ll>> x;
    ll i = 2;
    ll t = 0;
    while(m != 1 && i <= (ll)sqrt(n)){
        vector<ll> temp;
        if(m%i == 0){
            t++;
            m /= i;
        } else {
            if(t != 0){
                temp.push_back(i);
                temp.push_back(t);
                x.push_back(temp);
            }
            i++;
            t = 0;
        }
    }
    vector<ll> temp;
    temp.push_back(i); temp.push_back(t);
    x.push_back(temp);
    if(m != 1){
        vector<ll> temp;
        temp.push_back(n); temp.push_back(1);
        x.push_back(temp);
    }
    for(ll i = 0; i < x.size(); i++){
        ans += f(x[i][1]);
    }
    cout << ans << endl;
    return 0;
}
