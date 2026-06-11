#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    ll ans = 0;
    if(x == 1) ans += 300000; 
    if(y == 1) ans += 300000; 
    if(x == 2) ans += 200000; 
    if(y == 2) ans += 200000; 
    if(x == 3) ans += 100000; 
    if(y == 3) ans += 100000; 
    if(x == 1 && y == 1) ans += 400000;

    cout << ans << endl;

    return 0;
}

