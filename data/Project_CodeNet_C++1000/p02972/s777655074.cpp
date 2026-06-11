#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N; cin >> N;
    vector<int> a(N + 1); 
    for (int i = 1; i <= N; ++i) cin >> a[i];
    vector<int> b(N + 1, 0); 
    ll all = 0;
    for (int i = N; i >= 1; --i) {
        for (int j = 2; i * j <= N; ++j) b[i] += b[i * j];
        b[i] %= 2;
        b[i] = !(b[i] == a[i]);
        all += b[i];
    }
    cout << all << endl;
    for (int i = 1; i <= N; ++i) {
        if (b[i] == 1) cout << i << " ";
    }
    cout << endl;
}