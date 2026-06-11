#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

double dist(vi &v, int p) {
    int i;
    double d = 0;
    if (p == -1) {
        for (i = 0; i < v.size(); i++)
            d = max(d, (double)v[i]);
    } else {
        for (i = 0; i < v.size(); i++)
            d += pow(v[i], p);
        d = pow(d, 1.0 / p);
    }
    return d;
}

int main() {FIN
    
    int n, i, e;
    cin >> n;
    vi df(n);
    for (i = 0; i < n; i++) cin >> df[i];
    for (i = 0; i < n; i++) {
        cin >> e;
        df[i] = abs(df[i] - e);
    }
    
    cout << fixed << setprecision(8) << dist(df, 1) << "\n";
    cout << fixed << setprecision(8) << dist(df, 2) << "\n";
    cout << fixed << setprecision(8) << dist(df, 3) << "\n";
    cout << fixed << setprecision(8) << dist(df, -1) << "\n";
    
    return 0;
}

