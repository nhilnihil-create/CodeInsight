#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n+1,mod),b(m+1,mod),A(n+1),B(m+1);
    rep(i,n) cin >> a[i];
    rep(j,m) cin >> b[j];
    rep(i,n) A[i+1] = A[i] + a[i];
    rep(j,m) B[j+1] = B[j] + b[j];
    ll ans = 0,j = m;
    rep(i,n+1) {
        if(A[i] > k) break;
        while(B[j] > k - A[i]) {
            if(j == 0) break;
            j -= 1;
        }
        ans = max(ans, i + j);
    }
    cout << ans << endl;
}
