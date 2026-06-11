#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ll N;
    cin >> N;
    ll n = 1;
    //for(ll i = 0; i*i < N; i++) n = i + 1;

    ll ans = 0;
    ll now = 0;

    for(int i = 1; i <= N; i++) {
        ans += i*((N/i))*((N/i)+1)/2;
    }


    for(ll i = 1; i <= N && 0; i++) {
        now = 0;;
        ll temp = i;
        for(ll j = 1; j*j <= i; j++) {
            if(!(i%j)) {
                now += 2;
                if(i/j == j) now--;
            }
        }
        cout << i << ':' << now << endl;
        ans += now*i;
    }
    cout << ans << endl;
    
}