#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {

    int N, M;
    cin >> N >> M;

    int cnt = 0;
    
    rep(i, M) {
        int a;
        cin >> a;
        cnt += a;
    }

    if (N >= cnt) cout << N - cnt << endl;
    else cout << -1 << endl;

    return 0;
}
