#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll MINF = LLONG_MIN;
const int INT_INF = INT_MAX;

int main()
{
    string s;
    cin >> s;
    if (s == "Sunny")
        cout << "Cloudy" << endl;
    else if (s == "Cloudy")
        cout << "Rainy" << endl;
    else if (s == "Rainy")
        cout << "Sunny" << endl;
}