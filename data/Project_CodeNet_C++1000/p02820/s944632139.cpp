#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    ll N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    string point = T;
    ll ans = 0;
    rep(i,N) {
        if(i - K >= 0 && point.at(i) == point.at(i-K)) point.at(i) = 0;
        if (point.at(i) == 'r') ans += P;
        if (point.at(i) == 's') ans += R;
        if (point.at(i) == 'p') ans += S;
    }
    cout << ans << endl;
}
