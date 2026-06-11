#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll a, b, k; cin >> a >> b >> k;
    ll ansA = 0;
    ll ansB = 0;
    if (k <= a) {
        ansA = a - k;
        ansB = b;
    }
    else { // a < k
        ansB = max(0LL, b - k + a);
    }
    cout << ansA << " " << ansB << endl;
    return 0;
}