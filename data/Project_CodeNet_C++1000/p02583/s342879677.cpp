#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l.at(i);

    // choose three sticks and judge
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int p = l.at(i);
                int q = l.at(j);
                int r = l.at(k);
                if (p == q || q == r || p == r)
                    continue;
                else if (p + q <= r || q + r <= p || p + r <= q)
                    continue;
                else
                    count++;
            }
        }
    }

    // output
    cout << count << endl;
    return 0;
}