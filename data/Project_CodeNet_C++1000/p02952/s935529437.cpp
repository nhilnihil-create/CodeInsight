#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int numberOfDigets(int x) {
    int res = 0;
    if (x == 0) return 1;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int d = numberOfDigets(i);
        if (d&1) ans++;        
    }
    cout << ans << '\n';
    return 0;
}