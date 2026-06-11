#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = (N / (A + B)) * A + min(A, N % (A + B));
    cout << ans << endl;
}
