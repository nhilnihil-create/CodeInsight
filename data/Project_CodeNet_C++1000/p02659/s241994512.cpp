#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll a, b; double t;
    cin >> a >> t;
    b = 100LL * (t + 0.001);
    cout << a * b / 100 << endl;
    return 0;
}