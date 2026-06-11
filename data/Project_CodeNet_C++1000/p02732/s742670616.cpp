#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
vector<long long> a;

void solve() {
    map<long long, long long> ma;
    for(int i = 0; i < N; ++i)
        ma[a[i]]++;
    long long res = 0;
    for(auto it : ma)
        res += it.second * (it.second - 1) / 2;
    for(int i = 0; i < N; ++i) {
        long long val = ma[a[i]];
        long long before = val * (val - 1) / 2;
        long long after = (val - 1) * (val - 2) / 2;
        cout << res + after - before << endl;
    }
}

int main() {
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    solve();
}