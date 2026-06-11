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
    int n, k; cin >> n >> k;
    V<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    map<int, double> mp;
    for(int i = 1; i <= 1000; i++){
        int j = i;
        while(0 < j){
            double t = (double)j * (1.0 / (double)i);
            mp[i] += t;
            j--;
        }
    }

    V<double> v(n + 1);
    for(int i = 0; i < n; i++){
        v[i + 1] = v[i] + mp[p[i]];
    }

    double ans = 0;
    for(int i = k - 1; i <= n; i++){
        ans = max(ans, (v[i] - v[i - k]));
    }
    cout << setprecision(12) << ans << endl;

    return 0;
}
