#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N + 1), b(N + 1);
    rep(i, N) cin >> a[i + 1];
    for(int i = N; i >= 1; i--) {
        int cnt = 0;
        for(int j = N / i; j >= 1; j--) {
            if(b[i * j]) {
                cnt++;
            }
        }
        if(a[i] != cnt % 2) {
            b[i] = 1;
        }
    }
    int sum = accumulate(b.begin(), b.end(), 0);
    cout << sum << endl;
    if(sum) {
        for(int i = 1; i <= N; i++) {
            if(b[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
