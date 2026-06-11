#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){

    int n, m; cin >> n >> m;
    ll k; cin >> k;
    ll arr[n]; ll brr[m];
    int ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i] += (i==0 ? (ll)0 : arr[i-1]);
        if(arr[i] <= k) ans = i+1;
    }
    for(int i = 0; i < m; ++i){
        cin >> brr[i];
        brr[i] += (i==0 ? (ll)0 : brr[i-1]);
        if(brr[i] <= k) ans = max(ans, i+1);
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] > k) break;
        int pos = lower_bound(brr, brr+m, (ll)k-arr[i]) - brr;
        if(pos == m || brr[pos] > k-arr[i]) --pos;
        if(pos < 0) continue;
        ans = max(ans, i+pos+2);
    }
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
	return 0;
}

