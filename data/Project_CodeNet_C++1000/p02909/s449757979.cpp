#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e12

int const N = 1e3+5;

int main ()
{
    string s; cin >> s;
    if (s == "Sunny")
        cout << "Cloudy" << endl;
    else if (s == "Cloudy")
        cout << "Rainy" << endl;
    else if (s == "Rainy")
        cout << "Sunny" << endl;
    return 0;
}
