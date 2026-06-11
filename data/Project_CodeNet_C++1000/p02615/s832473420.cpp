#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n, greater<int>());
    ll ans = 0;
    ans += arr[0];
    for(int i = 2; i < n; ++i) ans += (ll)arr[i>>1];
    
    cout << ans << endl;
	return 0;
}