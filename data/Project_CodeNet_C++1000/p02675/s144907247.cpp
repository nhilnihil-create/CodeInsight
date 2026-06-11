#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int s;
    cin >> s;
    int mod = s % 10;

    if (mod == 3)
        cout << "bon";
    else if (mod == 0 || mod == 1 || mod == 6 || mod == 8)
        cout << "pon";
    else
        cout << "hon";
}