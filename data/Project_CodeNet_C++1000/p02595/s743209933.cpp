#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        long double xd = sqrt((x * x) + (y * y));
        if(xd <= d) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}