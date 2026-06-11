#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<ll> a;
    rep(i,n) {
        ll x;
        cin >> x;
        
        a.push(x);
    }
    
    rep(i,m) {
        ll x = a.top();
        a.pop();
        
        a.push(x / 2);
    }
    
    ll ans = 0;
    rep(i,n) {
        ans += a.top();
        a.pop();
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}
