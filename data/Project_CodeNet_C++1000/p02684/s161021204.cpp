#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    deque<int> b;
    vector<bool> seen(n, false);
    int cur = 0;
    while (true)
    {
        if (seen[cur])
        {
            while (b[0] != cur)
            {
                k--;
                b.pop_front();

                if (k == 0)
                {
                    cout << b[0] + 1 << endl;
                    return 0;
                }
            }
            break;
        }
        b.push_back(cur);
        seen[cur] = true;
        cur = a[cur];
    }

    cout << b[k % b.size()] + 1 << endl;

    return 0;
}