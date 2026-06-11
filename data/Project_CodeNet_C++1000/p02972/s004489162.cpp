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
    vector<ll> a(n+1);
    rep(i,n) cin >> a[i+1];
    vector<ll> ans(n+1); 
    ll sum = 0;
    
    for(ll i = n;i >= 1;--i){
        if(a[i] == 1) {
            ll an = 1;
            for(ll j = i+i;j <= n;j+=i){
                if(ans[j] == 1) an++;
            }
            if(an%2 == 1) {
                ans[i] = 1;
                sum++;
            }
        }else {
            ll an = 0;
            for(ll j = i+i;j <= n;j+=i){
                if(ans[j] == 1) an++;
            }
            if(an%2 == 1) {
                ans[i] = 1;
                sum++;
            } 
        }
    }

    cout << sum << endl;
    rep(i,n+1){
        if(ans[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
