#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += 1.0 / a[i];
    }

    cout << setprecision(12) << 1.0 / sum << endl;

    return 0;
}
