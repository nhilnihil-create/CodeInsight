#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<ll> q;
    
    ll ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        ans += a;
        q.push(a);
    }
    rep(i,m){
        ll a = q.top();
        ans -= a - a / 2;
        q.pop();
        q.push(a / 2);
    }
    cout << ans << endl;
    
    return 0;
}
