#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 2; i <= (int)(n); i++)
typedef long long ll;

int main() {
    ll N,K;
    cin >> N >> K;
    ll res = min(N%K,K-N%K);
    cout << res;
    return 0;
}
