#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int d, t, s;
    cin >> d >> t >> s;

    if (s * t >= d) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}