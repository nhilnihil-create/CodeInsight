#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin  >> arr[i];
    sort(arr, arr+n);
    cout << accumulate(arr, arr+k, 0);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

	return 0;
}

