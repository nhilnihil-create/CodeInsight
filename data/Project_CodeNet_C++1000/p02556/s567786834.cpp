#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> p(N);
    vector<int> m(N);
    rep(i, N){
        int x, y; cin >> x >> y;
        p[i] = x+y;
        m[i] = x-y;
    }

    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    int ans = max(p[N-1] - p[0], m[N-1] - m[0]);

    cout << ans << endl;

    return 0;
}