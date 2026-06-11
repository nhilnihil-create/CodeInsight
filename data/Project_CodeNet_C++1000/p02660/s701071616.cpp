#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin >> n;
    map<ll,ll> factor;
    ll nleft = n;
    for(ll i=2; 1<nleft && i*i<=nleft; i++){
        while(nleft%i == 0){
            factor[i]++;
            nleft /= i;
        }
    }
    if(2<=nleft) factor[nleft]++;
    ll count = 0;
    for(auto x: factor){
        ll left = x.second;
        for(ll i=1; i<=left; i++){
            left -= i;
            count++;
        }
    }

    cout << count;
    return 0;
}
