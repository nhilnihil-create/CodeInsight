#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<ll> h(N);
    rep(i, 0, N) { cin >> h[i]; }
    bool flg = true;

    int pre = -100;
    for(int i = 0; i < N; i++) {
        if(pre <= h[i] - 1) {
            pre = h[i] - 1;
        } else if(pre <= h[i]) {
            pre = h[i];
        } else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
