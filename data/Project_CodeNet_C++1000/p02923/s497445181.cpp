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
    V<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];;

    int cnt = 0, ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(h[i + 1] <= h[i]) cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);

    cout << ans << endl;
    return 0;
}
