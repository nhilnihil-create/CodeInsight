#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a = 0, b = 0, c = 0;
    cin >> a >> b >> c; 

    if(c - a - b > 0 && (c - a - b) * (c - a- b) > 4 * a * b) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}
