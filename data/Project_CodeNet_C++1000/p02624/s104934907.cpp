#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

void solve(){

    int n; cin >> n;
    vector<int> arr (n+1, 1);
    for(int i = 2; i <= n; ++i)
        for(int j = i; j <= n; j += i)
            ++arr[j];

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += (ll)i * (ll)arr[i];
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}

