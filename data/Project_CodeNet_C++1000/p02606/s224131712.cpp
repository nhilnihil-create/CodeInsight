#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int l, r, d;
    cin >> l >> r >> d;

    cout << r / d - (l - 1) / d << endl;
    return 0;
}
