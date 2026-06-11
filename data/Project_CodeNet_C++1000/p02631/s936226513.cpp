#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

void solve(){

    int n; cin >> n;
    ll xr = 0;
    ll arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        xr ^= arr[i];
    }
    for(int i = 0; i < n; ++i) cout << (xr ^ arr[i]) << " ";

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

	return 0;
}

