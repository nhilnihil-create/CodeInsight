#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n; ll sum = 0;
    cin >> n;
    for (ll i = 1; i < n; i++) sum += i;
    cout << sum << endl;
    return 0;
}