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
    priority_queue<pair<int,int>> pq;
    rep(i,n){
        if(a[i] > b[i]){cout << -1 << endl; return 0;}
        if(a[i] < b[i])pq.push({b[i],i});
    }
    ll ans = 0;
    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        int l = (i+n-1)%n, r = (i+1)%n;
        if(b[l]+b[r] > b[i] - a[i]){cout << -1 << endl; return 0;}
        int k = (b[i] - a[i]) / (b[l] + b[r]);
        ans += k;
        b[i] -= k*(b[l]+b[r]);
        if(a[i] < b[i])pq.push({b[i],i});
    }
    cout << ans << endl;
}