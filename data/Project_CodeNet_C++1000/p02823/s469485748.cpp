#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if((A - B)%2) {
        cout << min(A + B - 1,2*N - A - B + 1)/2 << endl;
    } else {
        cout << abs(A - B)/2 << endl;
    }

    return 0;
}