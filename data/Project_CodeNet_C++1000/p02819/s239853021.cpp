#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool f(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x%2 == 0) return false;

    double y = sqrt(x);
    for (int i = 3; i <= y; i += 2) {
        if (x%i == 0) return false;
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    for (int i = x;; i++) {
        if (f(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}