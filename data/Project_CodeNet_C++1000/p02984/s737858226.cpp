#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define erep(i, n) for (int i = 0; i <= (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<ll> A(n);
    ll x = 0;
    rep (i, n) {
        ll a; cin >> a;
        if (i % 2 == 0) x += a;
        else x -= a;
        A[i] = a;
    }
    cout << x << endl;
    rep (i, n - 1) {
        cout << A[i] * 2 - x << endl;
        x = A[i] * 2 - x;
    }
}
