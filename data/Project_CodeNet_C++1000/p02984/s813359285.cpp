#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    
    vector<ll> b(n);
    ll sum_a = 0;
    for(int i = 1; i <= n-2; i+=2) {
        sum_a += a[i];
    }
    b[0] = sum - 2 * sum_a;
    
    for(int i = 1; i < n; i++) {
        b[i] = 2*a[i-1] - b[i-1];
    }
    
    
    rep(i,n-1) cout << b[i] << " ";
    cout << b[n-1] << endl;
    
    
    
    return 0;
}
