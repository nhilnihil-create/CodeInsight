#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n], b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    ll suma[n+1], sumb[m+1];
    suma[0] = 0;
    sumb[0] = 0;
    rep(i, n) suma[i+1] = suma[i] + a[i];
    rep(i, m) sumb[i+1] = sumb[i] + b[i];
    ll ans = 0;
    ll idx = 0;
    for (ll i = n; i >= 0; i--){
        ll t = suma[i];
        while(idx < m && t + sumb[idx+1] <= k){
            idx++;
        }
        if(t+sumb[idx] <= k && i + idx > ans){
            ans = i + idx;
        }
        // cout << i << " " << idx << " " << t + sumb[idx] << endl;
    }
    cout << ans << endl;
}