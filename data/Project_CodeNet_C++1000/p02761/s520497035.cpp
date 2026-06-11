#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int A = 2e5 + 2;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    memset(a, -1, sizeof a);
    bool valid = 1;
    while(m--) {
        int x, y;
        cin >> x >> y, x--;
        if (~a[x] && a[x] != y)
            valid = 0;
        a[x] = y;
    }
    if (n > 1) {
        if (a[0] == 0)
            valid = 0;
        else {
            if (a[0] == -1)
                a[0] = 1;
            for (int i = 1; i < n; i++)
                 if (a[i] == -1)
                    a[i] = 0;
        }
    }
    else {
        if (a[0] == -1) a[0] = 0;
    }
    if (!valid) cout << -1;
    else {
        for (int i = 0; i < n; i++)
            cout << a[i];
    }
    return 0;
}