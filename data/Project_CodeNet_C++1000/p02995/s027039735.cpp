#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ans = (B-A+1)-(B/C-(A-1)/C)-(B/D-(A-1)/D)+(B/lcm(C,D)-(A-1)/lcm(C,D));
    cout << ans << endl;
}
