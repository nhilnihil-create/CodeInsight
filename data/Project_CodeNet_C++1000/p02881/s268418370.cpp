#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

pair<ll,ll> factorize(ll n){
    pair<ll,ll> res(1,n);
    for(ll i = 2;i*i <=n;i++){
        if(n % i == 0){
            ll p1 = i, p2 = n/i;
            if(abs(res.first+res.second) > abs(p1+p2)){
                res = make_pair(p1,p2);
            }
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    pair<ll,ll> cell = factorize(n);
    cout << cell.first+cell.second-2 << endl;
}