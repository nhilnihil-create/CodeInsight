#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define int ll

int32_t main() {
    ios::sync_with_stdio(0); 

    int n, d; 
    cin >> n >> d;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x*x + y*y <= d*d) cnt++;
    }

    cout << cnt << endl;


    return 0; 
}

