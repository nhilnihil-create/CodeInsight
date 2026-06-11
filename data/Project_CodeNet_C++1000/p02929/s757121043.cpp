#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;

    if(s.front() == 'W' || s.back() == 'W') {
        cout << 0 << endl;
        return 0;
    }

    int cntL = 1, cntR = 0;
    int flagL = 1;
    vector<ll> L(2*n), R(2*n);
    vector<int> posR;
    for(int i = 1; i < 2*n; i++) {

        L[i] = cntL;
        R[i] = cntR;

        if(s[i-1] == s[i]) {
            flagL ^= 1;
        }

        if(flagL) {
            cntL++;
        }
        else {
            cntR++;
            posR.push_back(i);
        }

    }

    if(cntL != cntR) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1LL;
    rep(i, posR.size()) {
        ans *= (L[posR[i]] - R[posR[i]]);
        ans %= mod;
    }

    while(n >= 1) {
        ans *= n;
        ans %= mod;
        n--;
    }
    
    cout << ans << endl;
    return 0;
}