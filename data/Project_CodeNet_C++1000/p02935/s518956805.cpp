#include <bits/stdc++.h>
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
    V<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(ALL(v));
    for(int i = 0; i < n - 1; i++){
        double t = (v[i] + v[i + 1]) / 2;
        v[i + 1] = t;
    }
    cout << v[n - 1] << endl;

    return 0;
}
