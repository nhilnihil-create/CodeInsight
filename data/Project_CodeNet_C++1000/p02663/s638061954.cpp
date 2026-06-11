#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int a, b, c, d, t;
        cin >> a >> b >> c >> d >> t;
        cout << (c * 60 + d) - (a * 60 + b) - t << "\n";
}
