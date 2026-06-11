#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<int> r;
vector<int> got;

int main()
{
    cin >> n;
    m = n;
    n = (1 << n);
    r.resize(n + 1);
    got.resize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> r[i];
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    got[0] = 1;
    for (int step = 1; step <= m; step++)
    {
        vector<int> have, create;
        for (int i = 0; i < n; i++)
        {
            if (got[i] == 1)
            {
                have.push_back(r[i]);
            }
            else
            {
                if (create.size() < have.size())
                {
                    if (r[i] < have[create.size()])
                    {
                        create.push_back(r[i]);
                        got[i] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (got[i] == 0)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}