#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ll N, *A, *L, *R;
    cin >> N;
    A = new ll[N], L = new ll[N], R = new ll[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        L[i] = A[i] + i;
        R[i] = i - A[i];
    }

    map<ll,ll> m;
    ll ans = 0;
    for (ll i = N-1; i >= 0; i--) {
        ans += m[L[i]];
        m[R[i]]++;
    }

    cout << ans << endl;

    return 0;
}