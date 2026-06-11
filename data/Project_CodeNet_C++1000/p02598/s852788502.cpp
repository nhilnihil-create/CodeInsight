#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l = 0,r = 1e9,m;
    while(r > 1 && l < r){
        m = (l+r)/2;
        ll cnt = 0;
        for(int i = 0; i < n; i++) cnt += (a[i]-1)/m;
        if(k < cnt) l = m+1;
        else r = m-1;
    }
    r = max(1ll,r-2);
    while(1){
        ll cnt = 0;
        for(int i = 0; i < n; i++) cnt += (a[i]-1)/r;
        if(cnt <= k){
            cout << r << endl;
            return 0;
        }else r++;
    }
}