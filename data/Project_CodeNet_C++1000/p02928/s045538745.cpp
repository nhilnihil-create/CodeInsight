#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main() {
    ll n,k; cin >> n >> k;
    vector<ll> a(n); rep(i,n) cin >> a[i];

    ll p1 = 0;
    rep(i,n){
        for(ll j= i+1; j<n; j++){
            if(a[i] > a[j]){
                p1++;
            }
        }
    }

    ll p2 = 0;
    rep(i,n){
        rep(j,n){
            if(a[i] > a[j]) p2++;
        }
    }

    ll ans = 0;
    ans += p1 * k;
    ans %= 1000000007;
    ans += (k*(k-1)/2)% 1000000007 * p2 %1000000007;
    ans %= 1000000007;

    cout << ans << endl;
}