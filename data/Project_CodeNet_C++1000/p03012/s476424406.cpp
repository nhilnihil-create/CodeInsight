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
    V<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    V<int> v(n + 1);
    for(int i = 0; i < n; i++){
        v[i + 1] = v[i] + w[i];
    }


    int ans = IINF;
    for(int i = 1; i < n; i++){
        int a = v[i];
        int b = v[n] - v[i];
        ans = min(abs(a - b), ans);
    }
    cout << ans << endl;

    return 0;
}
