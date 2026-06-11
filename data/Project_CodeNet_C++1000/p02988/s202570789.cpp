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
    V<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(p[i - 1] < p[i] && p[i] < p[i + 1] ||
            p[i + 1] < p[i] && p[i] < p[i - 1])
            ans++;
    }
    cout << ans << endl;

    return 0;
}
