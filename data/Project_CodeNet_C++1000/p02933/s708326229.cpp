#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int a;
    string s;
    cin >> a >> s;
    cout << (a >= 3200 ? s : "red") << endl;
    return 0;
}