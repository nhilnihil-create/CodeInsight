#include <bits/stdc++.h>
#define rep(i, n) for (long long i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    ll x = N;
    if (N >= B-1) x = B-1;
    ll ans = A*(x%B)/B;
    cout << ans << endl;
    return 0;
}