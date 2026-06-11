#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Check(const vector<int> &index, const vector<vector<pair<int, int>>> &a)
{
    for (auto i : index)
    {
        for (const auto &j : a[i])
        {
            if (j.second == 1)
            {
                if (std::find(index.begin(), index.end(), j.first - 1) == index.end())
                {
                    return false;
                }
            }
            else
            {
                if (std::find(index.begin(), index.end(), j.first - 1) != index.end())
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int x, y;
            cin >> x >> y;
            a[i].emplace_back(x, y);
        }
    }

    int max = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> index;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                index.push_back(j);
            }
        }
        if (Check(index, a))
        {
            max = max < index.size() ? index.size() : max;
        }
    }

    cout << max << endl;
}
