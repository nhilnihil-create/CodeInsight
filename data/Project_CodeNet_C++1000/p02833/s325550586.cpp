#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;

    ll ans = 0;
    if (n % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll i = 5;
    ll count = 0;
    while(n / 2 >= i){
        i *= 5;
        count++;
    }
    i /= 5;
    if (count == 0){
        cout << 0 << endl;
        return 0;
    }
    ll total = 0;
    for(int j = count; j > 0; j--){
        ll k = (n/2)/ i;
        k -= total;
        ans += j * k;
        total += k;
        i /= 5;
    }
    cout << ans << endl;
    return 0;
}