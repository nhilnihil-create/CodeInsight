#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll sum = 1e13;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0) sum = min(sum, n/i + i);
    }

    cout << sum-2 << endl;
}