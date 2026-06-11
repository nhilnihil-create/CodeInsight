#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;
    ll ans = (n + 1) - 2;

    for(ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            ll p = n / i;
            ans = min(ans, (p + i) - 2);
        }
    }
    cout << ans << endl;
    return 0;
}