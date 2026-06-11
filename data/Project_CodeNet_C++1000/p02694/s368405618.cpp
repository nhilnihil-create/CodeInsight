#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll x;
    cin >> x;
    ll now = 100;
    ll i = 0;
    while(now < x){
        now += now/100;
        ++i;
    }
    cout << i << endl;
    return 0;
}