#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{

   //// freopen("input.txt", "r", stdin);
   /// freopen("output.txt", "w", stdout);
    int x, y;
    cin >> x >> y;
    if (y % 2 == 0 && y >= 2 * x && y <= 4 * x)
    {
        cout << "Yes\n";
    }
    else
        cout << "No"
             << "\n";
    return 0;
}