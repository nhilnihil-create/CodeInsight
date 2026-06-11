#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    
    int ans = 0;
    cout << min(n % k, k - n % k) << endl;

    return 0;
}