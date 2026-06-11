#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

bool is_prime(ll n){
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return n != 1;
}

void solve(long long X){
    ll x = X;
    for(ll i = 0; i < INF; ++i){
        if(is_prime(x)) break;
        x = X + i;
    }
    cout << x << endl;
    return;
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
