#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[200000], ans = 0;
    cin >> n;
    for (int in = 0; in < n; in++)
    {
        cin >> a[in];
    }

    int des = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == des)
        {
            des++;
            ans++;
        }
    }

    if (des == 1) cout << -1 << endl;
    else cout << n - ans << endl;
}