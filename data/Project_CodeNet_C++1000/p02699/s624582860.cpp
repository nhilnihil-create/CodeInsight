#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int s,w;
    cin >> s >> w;
    if (w>=s)
    {
        cout << "unsafe" << endl;
    }
    else
    {
        cout << "safe" << endl;
    }

    return 0;
}