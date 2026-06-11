#include <bits/stdc++.h>
using namespace std;

const int NMAX = 55;
int a[NMAX], n, b[NMAX];

bool sorted(int v[]) {
    for(int i = 1; i < n; i++) {
        if(v[i] > v[i + 1]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool ok = 0;
    if(sorted(a)) {
        ok = 1;
    }
    for(int i = 1; i <= n && ok == 0; i++) {
        for(int j = i + 1; j <= n && ok == 0; j++) {
            for(int k = 1; k <= n; k++) {
                b[k] = a[k];
            }
            swap(b[i], b[j]);
            if(sorted(b)) {
                ok = 1;
            }
        }
    }
    if(ok) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
