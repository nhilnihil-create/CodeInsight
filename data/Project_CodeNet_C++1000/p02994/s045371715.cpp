#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;

    vector<int> aji(n);
    for (int i = 0; i < n; i++)
        aji[i] = l + (i + 1) - 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += aji[i];
    int dif = 1e9, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = abs(sum - (sum - aji[i]));
        if (dif > tmp)
        {
            dif = tmp;
            ans = sum - aji[i];
        }
    }

    cout << ans << endl;
    return 0;
}