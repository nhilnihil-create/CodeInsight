#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 100000007;

int main() {
    ll A,B,N;cin >> A >> B >> N;
    ll x;
    if (N >= B) x = B - 1;
    else x = N;
    int ans = ((A * x) / B) - A * (x / B);
    cout << ans << endl;
}