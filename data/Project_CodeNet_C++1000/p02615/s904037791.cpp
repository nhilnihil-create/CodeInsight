#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
 
int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    deque<ll> q;
    rep(i, 2) q.push_back(a[1]);
    ll ans = a[0];
    for(int i = 2; i < n; ++i){
        ans += q.front(); q.pop_front();
        rep(j, 2) q.push_back(a[i]);
    }
    cout << ans << endl;
    return 0;
}