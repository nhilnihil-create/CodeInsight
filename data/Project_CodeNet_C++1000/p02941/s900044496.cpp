#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    priority_queue<pair<ll,ll>> q;
    rep(i,n){
        if(b[i]>a[i])q.push({b[i],i});
        else if(b[i] < a[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    while(!q.empty()){
        int i = q.top().second;q.pop();
        int r = (i+1)%n, l = (i-1+n)%n;
        if( b[i] - a[i] >= b[l] + b[r]){
            int k = (b[i] - a[i]) / (b[l] + b[r]);
            ans += k;
            b[i] -= k*(b[l]+b[r]);
            if(b[i] > a[i])q.push({b[i],i});
            else if(b[i] < a[i]){cout << -1 << endl; return 0;}
        }else {cout << -1 << endl; return 0;}
    }
    cout << ans << endl;
}
