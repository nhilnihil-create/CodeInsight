#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = n * (n-1) + m * (m-1);
    ans /= 2;
    cout << ans << endl;
}
