#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    ll root = sqrt(n);
    ll x = root;
    while(true){
        if(n % x == 0) break;
        x--;
    }
    ll other = n / x;
    cout << x + other - 2 << endl;
}