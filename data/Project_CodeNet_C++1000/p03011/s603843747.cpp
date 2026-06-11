#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int P, Q, R;
    cin >> P >> Q >> R;

    int m = max(P, max(Q, R));

    cout << P + Q + R - m << endl;

    return 0;
}