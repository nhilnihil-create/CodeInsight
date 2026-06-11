#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;

void solve(){

    int n; cin >> n;
    
    if(n % 10 == 3) cout << "bon";
    else if(n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8) cout << "pon";
    else cout << "hon";

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

