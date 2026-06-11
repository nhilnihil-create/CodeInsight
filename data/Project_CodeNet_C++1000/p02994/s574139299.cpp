#include <bits/stdc++.h>
using namespace std;
const int N = 202;
int n, l;

int main() {
    cin >> n >> l;
    int ans = -1, v = 1e5;
    for(int i=1; i<=n; i++) {
        int u = abs(i+l-1);
        if(u < v) {
            v = u;
            ans = n*(n+1)/2 - i + (n-1)*(l-1);
        }
    }
    cout << ans;
}
