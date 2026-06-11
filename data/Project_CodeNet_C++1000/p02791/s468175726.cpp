#include <iostream>
#include <algorithm>
using namespace std;

long long n, p[200001], pmin[200001], ans = 0;

int main()
{
    cin >> n;
    for (int i = 0; i <= 200000; i++) pmin[i] = 200000;
    //for (int i = 1; i <= n; i++) cout << "i: " << pmin[i] << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pmin[i] = min(pmin[i - 1], p[i]);
    }
    //for (int i = 1; i <= n; i++) cout << "i: " << pmin[i] << endl;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] <= pmin[i]) ans++;
    }

    cout << ans << endl;
}