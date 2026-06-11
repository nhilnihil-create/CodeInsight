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

    string s;
    cin >> s;

    if (s=="Sunny")
    {
        cout << "Cloudy" << endl;
    }
    else if (s=="Cloudy")
    {
        cout << "Rainy" << endl;
    }
    else if (s=="Rainy")
    {
        cout << "Sunny" << endl;
    }

    return 0;
}