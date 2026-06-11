#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;
#define rep1(i,n) for (int i=1; i<=n; i++)
#define rep0(i,n) for (int i=0; i<n; i++)
#define zarray(x,n) x[n+1]; rep1(i,n) {x[i]=0;} 

int main() {
    int s, w;
    cin >> s >> w;
    string ans = "unsafe";
    if (s > w) {
        ans = "safe";
    }
    cout << ans << endl;
}
