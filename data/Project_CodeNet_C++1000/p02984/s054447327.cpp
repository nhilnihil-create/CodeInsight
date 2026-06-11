#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans(n);
    rep(i,n){
        if(i%2 == 0) ans[0] += a[i];
        else ans[0] -= a[i];
    }
    ans[0] /= 2;
    rep(i,n-1){
        ans[i+1] = a[i] - ans[i];
    }
    rep(i,n) cout << 2*ans[i] << " ";
    cout << endl;
    return 0;
}
