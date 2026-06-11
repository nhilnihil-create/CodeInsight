#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
using LP = pair<ll,ll>;
using P = pair<ll,int>;

int main()
{
    int n, m;
    cin >> n>> m;
    priority_queue<ll, vector<ll>> a;
    rep(i, n){
        ll x;cin >> x;
        a.push(x);
    }
    rep(i, m){
        ll u = a.top();a.pop();
        a.push(u/2);
    }
    ll ans = 0;
    rep(i, n) {
        ans += a.top();a.pop();
    }
    cout << ans << endl;
}