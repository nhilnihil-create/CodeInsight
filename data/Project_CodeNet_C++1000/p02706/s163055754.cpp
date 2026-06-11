#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    int x = 0, ans;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        x += a;
    }
    if (x <= n) {
        ans = n-x;
    }
    else {
        ans = -1;
    }
    cout << ans << endl;
}