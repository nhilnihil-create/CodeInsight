#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    long long X,K,D; cin >> X >> K >> D;
    long long ans;
    X = abs(X);
    long long straight = min(K, X/D);
    K -= straight;
    X -= straight*D;

    if (K%2 == 0) cout << X << endl;
    else cout << D - X << endl;
}
