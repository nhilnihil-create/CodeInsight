#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;
#define rep1(i,n) for (int i=1; i<=n; i++)
#define rep0(i,n) for (int i=0; i<n; i++)
#define zarray(x,n) x[n+1]; rep1(i,n) {x[i]=0;} 

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string ans = "No";
    for (;;) {
        c -= b;
        if (c <= 0) {
            ans = "Yes";
            break;
        }
        a -= d;
        if (a <= 0) {
            break;
        }
    }
    cout << ans << endl;
}
