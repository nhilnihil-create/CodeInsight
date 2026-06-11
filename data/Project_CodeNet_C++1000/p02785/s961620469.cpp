#include <bits/stdc++.h>
#include <functional>
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
    V<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    ll ans = 0;
    sort(ALL(h), greater<int>());
    for(int i = 0; i < n; i++){
        if(0 < k){
            k--;
            continue;
        }else{
            ans += h[i];
        }
    }
    cout << ans << endl;



    return 0;
}
