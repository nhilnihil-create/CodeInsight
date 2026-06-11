#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    for (ll i = 0; i < N; i++) cin >> A.at(i);
    for (ll i = 0; i < M; i++) cin >> B.at(i);

    ll ans = 0, i = 0, j = 0, T = K;
    while (true) {
        if (i >= M) {
            i--;
            break;
        }
        if (T - B.at(i) >= 0) {
            T -= B.at(i);
            i++;
            ans++;
        } else {
            i--;
            break;
        }
    }
    ll tmp = ans;
    while (j < N) {
        //cout << tmp << ": i = " << i << ", j = " << j << ", T = " << T << endl;
        if (T - A.at(j) >= 0) {
            T -= A.at(j);
            j++;
            tmp++;
        } else {
            if (i >= 0) {
                T += B.at(i);
                i--;
                tmp--;
            } else break;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
