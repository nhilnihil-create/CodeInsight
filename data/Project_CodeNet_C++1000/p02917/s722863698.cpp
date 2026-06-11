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
    V<int> b(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> b[i];

    int ans = b[0];
    for(int i = 1; i < n - 1; i++){
        if(b[i - 1] < b[i]) ans += b[i - 1];
        else ans += b[i];
    }
    ans += b[n - 2];
    cout << ans << endl;

    return 0;
}
