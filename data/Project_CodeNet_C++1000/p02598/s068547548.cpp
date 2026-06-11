#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int lb = 1, ub = 1000000000;
    while (lb != ub)
    {
        int t = (lb + ub) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
            count += (a[i] / t + (a[i] % t != 0) - 1);

        if (count <= k)
            ub = t;
        else
        {
            if (t == lb)
                break;
            lb = t;
        }
    }
    cout << ub << endl;
}