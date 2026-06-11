#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    string N;
    cin >> N;
    ll a = 0, b = 1;
    for(auto i = N.begin(); i!= N.end(); i++){
        int t = *i - '0';
        ll ta = min({a + t, b + (10 - t)});
        ll tb = min(a + (t + 1), b + (10 - t - 1));
        a = ta;
        b = tb;
    }
    cout << a << endl;
}