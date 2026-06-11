#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> c(n);

    int total = 0;
    for (int i=0; i<n; i++)
    {
        cin >> c[i];
        total += c[i];
    }

    auto lb = total/n;
    auto ub = lb + 1;
    sort(c.begin(), c.end());

    int curr1 = 0, curr2 = 0;
    for (auto jk : c)
    {
        curr1 += (jk - lb)*(jk - lb);
        curr2 += (jk - ub)*(jk - ub);
    }

    if (curr1 < curr2) cout << curr1;
    else cout << curr2;

    return 0;
}

