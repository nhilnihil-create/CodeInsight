#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;

int main(){
    ll x;
    cin >> x;
    ll money = 100;
    ll ans = 0;
    while(money<x){
        ans++;
        money += money/100;
    }
    cout << ans << endl;
}
