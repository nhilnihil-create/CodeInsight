#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lin "\n"
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)

void solve() {
    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout.precision(0);
    cout << fixed << max(a * c, max(a * d, max(b * c, b * d))) << lin;
}

int main() {
    fast_io;
    int t = 1;
//    cin >> t;
//    scanf("%d",&t);
    int c = 1;
    while (t--) {
//        printf("Case %lld: ",c);
//        cout<<"Case "<<c<<": ";
        solve();
        c++;
    }
}