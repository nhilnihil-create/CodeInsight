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
    V<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        a[i] = x;
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b[i] = x;
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        c[i] = x;
    }

    int ans = 0, pre = -2;
    for(int i = 0; i < n; i++){
        if(pre + 1 == a[i]){
            ans += (b[a[i]] + c[pre]);
        }else{
            ans += b[a[i]];
        }
        pre = a[i];
    }
    cout << ans << endl;

    return 0;
}
