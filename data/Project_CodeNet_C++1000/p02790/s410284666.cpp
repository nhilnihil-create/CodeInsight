#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B;
    cin >> A >> B;
    if (A < B) {
        rep(i, B) cout << A;
        cout << endl;
    }

    else {
        rep(i, A) cout << B;
        cout << endl;
    }
}
