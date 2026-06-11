#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1, 0), b(n+1, 0);
    for (ll i=1; i<=(n); i++) cin >> a[i];
    for (ll i=n; i>0; i--){
        ll sum = 0;
        for (ll j=i; j<=n; j+=i){
            sum += b[j];
        }
        sum = sum % 2;
        if (sum!=a[i]) b[i]++;
    }
    vector<ll> ans;
    rep1(i, n+1) if (b[i]==1) ans.push_back(i);
    cout << ans.size() << endl;
    if (ans.size()>0) rep1(i, ans.size()){
        if (i==ans.size()-1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    //printf("%.12f", ans);
}