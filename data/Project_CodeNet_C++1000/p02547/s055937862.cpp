#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main()
{
    fastio;
    int n, x, y, d=0;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        if (x == y) d++;
        else d = 0;
        if (d == 3) {cout << "Yes"; return 0;}
    }
    cout << "No";
}
