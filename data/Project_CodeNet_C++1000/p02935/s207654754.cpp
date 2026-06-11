#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<float> vect(n);
    rep(i, n) { cin >> vect[i]; }

    sort(vect.begin(), vect.end());

    float sum;
    sum = (vect[0] + vect[1]) / 2;
    if (n > 2) {
        for (ll i = 2; i < n; i++) {
            sum = (sum + vect[i]) / 2;
        }
    }

    cout << sum << endl;
}