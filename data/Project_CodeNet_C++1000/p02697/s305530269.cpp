#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int x=1, y=n;
    for (int dist=(n-1)/2; m && dist>0; --m, --dist) {
        if (dist&1)     cout << y << " " << y-dist << "\n", --y;
        else            cout << x << " " << x+dist << "\n", ++x;
    }

    return 0;
}
