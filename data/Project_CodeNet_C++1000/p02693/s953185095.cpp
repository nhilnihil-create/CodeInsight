#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;


void solve(){

    int n, a, b; cin >> n >> a >> b;
    if(((a+n-1) / n) * n <= b) cout << "OK";
    else cout << "NG";
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
