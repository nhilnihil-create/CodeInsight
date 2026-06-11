#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    int n, m; cin >> n >> m;
    ll ans = 0; 
    ans += n * (n-1) / 2;
    ans += m * (m-1) / 2;
    cout << ans << endl;



    return 0; 
}

