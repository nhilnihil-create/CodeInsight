#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const double pi = 3.141592653589793;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    rep(i,M) cin >> A.at(i);
    ll total = 0;
    rep(i,M) total += A.at(i);
    if (total > N) cout << -1 << endl;
    else cout << N - total << endl;
}

