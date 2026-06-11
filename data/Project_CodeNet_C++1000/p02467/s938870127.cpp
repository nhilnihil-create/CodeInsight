#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    cout << n << ":";
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << " " << i;
            n /= i;
        }
    }
    if (n != 1) cout << " " << n;
    cout << "\n";
}
