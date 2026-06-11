#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll md = 1000000007;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h, cnt = 0, c = 1;
    cin >> h;
    while(h >= 1) {
    	cnt += c;
    	c *= 2;
    	h /= 2;
    }
    cout << cnt << "\n";
    return 0;
}
