#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double d;
    cin >> n >> d;
    int sum= 0;
    for (int i= 0;i< n;i++) {
        long long x, y;
        cin >> x >> y;
        double dis= sqrt(x* x+ y* y);
        if (dis <= d) sum++;
    }
    cout << sum << endl;
}