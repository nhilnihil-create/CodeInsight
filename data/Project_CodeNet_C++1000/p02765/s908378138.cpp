#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


signed main() {
    int N, R;
    cin >> N >> R;
    if (N > 9) cout << R << endl;
    else cout << R + ((10 -N) * 100) << endl;

}
