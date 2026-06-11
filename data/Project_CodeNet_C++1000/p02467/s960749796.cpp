#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
    
    ll n; cin >> n;
    cout << n << ":";
    for (ll nn = n, i = 2; i*i <= nn; i++) {
        while (n % i == 0) {
            cout << " " << i;
            n /= i;
        }
    }
    if (n > 1) {
        cout << " " << n;
    }
    cout << endl;
    
}
