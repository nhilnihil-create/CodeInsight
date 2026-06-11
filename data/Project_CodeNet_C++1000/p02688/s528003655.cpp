#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, l, tmp, res = 0;
    cin >> n >> k;
    vector<int> snu(n);

    for(int i = 0; i < k; ++i)
    {
        cin >> l;
        for(int j = 0; j < l; ++j)
        {
            cin >> tmp;
            snu[tmp - 1]++;
        }
    }

    for(auto i: snu)
    {
        res += i ? 0 : 1;
    }

    cout << res << "\n";
}