#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int mod  = 1e9 + 7;
const ll INF = 1e14;

void solve(){

    char c; cin >> c;
    cout << (c & (1<<5) ? 'a' : 'A');

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

	return 0;
}

