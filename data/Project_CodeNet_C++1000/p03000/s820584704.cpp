#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, X;
    cin >> N >> X;

    int l[N + 1];
    l[0] = 0;
    rep(i, N) cin >> l[i + 1];
    int d = 0;
    int cnt = 0;
    rep(i, N+1) {
        d += l[i];
        if (d <= X) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}