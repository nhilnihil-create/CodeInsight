#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    H[0]--;
    for (int i = 1; i < N; i++) {
        if (H[i] > H[i-1]) H[i]--;
        else if (H[i] < H[i-1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}