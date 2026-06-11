#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    int x , n;
    cin >> x >> n;
    vi p(102);
    rep(i, n) {
        int d;
        cin >> d;
        p.at(d) = 1; 
    }

    pii ans(99999, -1);

    for (int i = 0; i <= 101; i++) {
        if (p.at(i) == 1) continue;
        int dif = abs(x - i);
        ans = min(ans, pii(dif, i));
    }

    cout << ans.second << endl;
    return 0;
}