#include <bits/stdc++.h>
#define ll long long
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

int main() { _
    ll n, m, k, sum = 0, ans = 0, max1 = 0, l = 0, r = 0; cin >> n >> m >> k;
    deque <ll> dq1, dq2;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        dq1.push_back(x);
    }
    for(ll i = 0; i < m; i++){
        ll x; cin >> x;
        dq2.push_back(x);
    }
    while(l < n){
        if(sum + dq1[l] <= k){
            sum += dq1[l];
            ans++;
            l++;
        }else{
            l--;
            break;
        }
    }
    if(l == n) l--;
    max1 = max(max1, ans);
    while(l >= -1 && r < m){
        if(sum + dq2[r] <= k){
            sum += dq2[r];
            ans++;
            r++;
        }else{
            if(l < 0) break;
            sum -= dq1[l];
            l--;
            ans--;
        }
        max1 = max(ans, max1);
    }
    max1 = max(ans, max1);
    cout << max1 << endl;
}