#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 5;
const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078;
//iostream::sync_with_stdio(false);

int main()
{
    int m[35] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int n;
    cin >> n;
    cout << m[n - 1] << endl;
    return 0;
}

