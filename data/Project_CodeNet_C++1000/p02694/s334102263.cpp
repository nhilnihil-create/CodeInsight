#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;


void solve(){

    ll n; cin >> n;
    ll st = 100, ans = 0;
    while(st < n){
        st += st/100;
        ++ans;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int test; cin >> test;
    //for(int t = 1; t <= test; ++t){
        solve();
    //}

	return 0;
}
