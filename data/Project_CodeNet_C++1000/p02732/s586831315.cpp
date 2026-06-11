#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
ll N;
cin >> N;
vector<ll> vec(N+1);
map<ll,ll> b,c;
for(ll i = 1;i <= N;i++) {
    cin >> vec.at(i);
    if (b.count(vec.at(i))) b[vec.at(i)]++;
    else b[vec.at(i)] = 1;
}
ll ans = 0;
for (ll i = 1;i <= N;i++) {
    if (b.count(i) && b[i] > 1)  ans += b[i] * (b[i]-1) / 2;
}
for (ll i = 1;i <= N;i++) {
    if (b[vec.at(i)] > 1) {
        cout << ans - b[vec.at(i)]+1 << endl;
    } else cout << ans << endl;
}

return 0;
}



