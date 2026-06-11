#include <bits/stdc++.h>
using namespace std;

int main() {
    double ans;
    int N;
    cin >> N;
    int x = (N + 1) / 2;
    ans = double(x) / N;

    cout << fixed << setprecision(10) << ans << endl;
}