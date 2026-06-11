#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<int(n); i++)
#define print(x) cout << (x) << endl

bool isPrime(int n) {
    for (int i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    int x; cin >> x;
    for (int i=x; ; i++) {
        if (isPrime(i)) {
            cout << i << endl;
            break;
        }
    }
}