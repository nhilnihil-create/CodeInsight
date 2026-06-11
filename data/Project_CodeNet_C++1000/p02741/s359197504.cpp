#include <bits/stdc++.h>

#define MAX(a , b) (a > b? a : b)
#define MIN(a , b) (a < b? a : b)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

const double pi = 2.0*acos(0.0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int n;
    cin >> n;
    cout << a[n-1] << endl;

    return 0;
}
