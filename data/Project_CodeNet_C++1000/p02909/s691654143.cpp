#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    if (s.at(0) == 'S')
        cout << "Cloudy";
    else if (s.at(0) == 'C')
        cout << "Rainy";
    else
        cout << "Sunny";
}