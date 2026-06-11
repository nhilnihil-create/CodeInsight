#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    if (n < m)
        swap(n, m);

    cout << (x + n - 1) / n;

    return 0;
}   