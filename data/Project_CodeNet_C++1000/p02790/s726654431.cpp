#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int a, b;
    cin >> a >> b;

    int c = min(a, b);
    int d = max(a, b);

    rep(i, d) {
        cout << c;
    }

    cout << endl;

    return 0;
}