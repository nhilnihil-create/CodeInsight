#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1e9+7;
// const ll INF = 1000000000000000000LL;

 int main() {
		int n;
    cin >> n;
    vector<ll> A(n), x(n);
 
    ll res = 0;
    rep(i, n) {
        cin >> A[i];
        if (i % 2) res -= A[i];
        else res += A[i];
    }
    
    x[0] = res;
 
    rep(i,n-1) {
        x[i+1] =2 * A[i] - x[i];
    }
 
    rep(i, n) cout << x[i] << endl;
 
    return 0;
 }