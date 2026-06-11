#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int mx = *max_element(arr, arr+n);
    vector<int> present (mx+1, 0);
    for(int i = 0; i < n; ++i) ++present[arr[i]];
    int ans = 0;
    for(int i = 1; i <= mx; ++i){
        if(present[i] == 0) continue;
        if(present[i] == 1) ++ans;
        for(int j = 2*i; j <= mx; j += i)
            present[j] = false;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

	return 0;
}