#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//A=65,a=97

int main() {
    ll n,k;cin >> n >> k;
    ll sum = 0;
    for(ll i = k; i <= n+1; i++) {
        ll x=(0 + i-1)*i/2;
        ll y=(n-i+1 + n)*i/2;
        sum += y-x+1;
        sum %= INF;
    }

    cout << sum << endl;

    return 0;
}