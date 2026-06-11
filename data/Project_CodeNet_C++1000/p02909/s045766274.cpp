#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

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
    return 0;
}