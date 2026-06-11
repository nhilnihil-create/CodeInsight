#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a.at(i);
    int cnt = 0;
    rep(i,N) if (a.at(i) == cnt + 1) ++cnt;
    if (cnt != 0) cout << N - cnt << endl;
    else cout << -1 << endl;
}
