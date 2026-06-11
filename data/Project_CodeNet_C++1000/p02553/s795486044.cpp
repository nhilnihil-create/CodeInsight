#include <bits/stdc++.h>
using namespace std;


int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a*c, a*d, b*c, b*d}) << '\n';
    return 0;
}
