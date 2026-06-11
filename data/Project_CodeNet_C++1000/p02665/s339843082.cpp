#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<pair<ll,ll>> r(n+2);
    rep(i,n+1)cin >> a[i];
    r[n].first = r[n].second = a[n];
    for(int i=n-1;i>=0;i--){
        r[i].first = (r[i+1].first+1)/2 + a[i];
        r[i].second = r[i+1].second + a[i];
    }
    if(r[0].first > 1){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    ll cur = 1;
    for(int i=0;i<=n;i++){
        ans += cur;
        cur -= a[i];
        cur = min(cur*2,(ll)r[i+1].second);
    }
    cout << ans << endl;
}
