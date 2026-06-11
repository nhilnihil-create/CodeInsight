#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll MAX = 200000, INF = 1e13;
ll n, k;
 
ll A[MAX], B[MAX], F[MAX];
 
bool C(ll x) {
    ll cnt = 0;
    sort(A, A + n);
    sort(F, F + n, greater<>());
    for (int i = 0; i < n; i++) {
        B[i] = x/F[i];
    }
    for (int i = 0; i < n; i++) {
        if (B[i] < A[i]) cnt += A[i] - B[i];
    }
    if (cnt > k) return false;
    else return true;
}
 
void solve() {
    ll lb = 0, ub = INF;
    for (int i = 0; i < 100; i++) {
        ll mid = (lb + ub) / 2;
        if (C(mid)) ub = mid;
        else lb = mid;
    }
 
    printf("%lld\n", ub);
}
 
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> F[i];
 
    solve();
}