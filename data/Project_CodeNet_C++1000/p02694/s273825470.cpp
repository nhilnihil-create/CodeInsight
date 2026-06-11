#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ll x, a = 100, ans = 0;
    cin >> x;
    while (a < x) {
        a += a/100;
        ans ++;
    }
    cout << ans << endl;
}