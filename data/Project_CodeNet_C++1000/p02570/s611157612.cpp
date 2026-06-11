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

    int d,t,s;
    cin >> d >> t >> s;
    int a=t*s;

    if (a<d)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}