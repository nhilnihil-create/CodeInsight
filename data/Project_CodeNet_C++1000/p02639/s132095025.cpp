#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int ans = 15;
    int x, i = 5;
    while (i--)
    {
        cin >> x;
        ans -= x;
    }
    cout << ans << "\n";
    return 0;
}