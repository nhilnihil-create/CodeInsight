#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
ll mod = 1000000007;


int main() {
    ll x; cin >> x;
    ll ans = 0;
    ll tmp = 100;
    while (tmp < x) {
        ans++;
        tmp += tmp /100;
    }
    cout << ans << "\n";
}