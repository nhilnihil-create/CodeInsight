#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int K, X;
    cin >> K >> X;

    for (int i = X - K + 1; i < X + K; ++i) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}