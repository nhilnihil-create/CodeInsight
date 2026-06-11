#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int p, q, r, r1, r2, r3, result;
    cin >> p >> q >> r;
    r1 = p + q;
    r2 = r + p;
    r3 = q + r;
    result = min(r1, r2);
    result = min(result, r3);
    cout << result;
    return 0;
}
