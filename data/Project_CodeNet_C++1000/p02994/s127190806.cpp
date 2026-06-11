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
    int n, l; cin >> n >> l;

    V<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++){
        a[i] = l + i;
        s += a[i];
    }

    int x = IINF;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int t = s - a[i];
        if(abs(s - t) < x){
            x = abs(s - t);
            ans = t;
        }
    }
    cout << ans << endl;

    return 0;
}
