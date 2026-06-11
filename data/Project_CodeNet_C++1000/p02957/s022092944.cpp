#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int c = a+b;
    if(c%2) cout << "IMPOSSIBLE" << endl;
    else cout << c/2 << endl;

    return 0;
}
