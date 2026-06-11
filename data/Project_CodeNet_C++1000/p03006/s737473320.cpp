#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

void select(vector<bool>& visited, vector<pair<int64_t, int64_t>>& vs, pair<int64_t, int64_t> pq, int i)
{
    visited[i] = true;
    for (int j = 0; j < vs.size(); j++)
    {
        if (!visited[j] && vs[i].first + pq.first == vs[j].first && vs[i].second + pq.second == vs[j].second)
        {
            select(visited, vs, pq, j);
        }
        else if (!visited[j] && vs[i].first - pq.first == vs[j].first && vs[i].second - pq.second == vs[j].second)
        {
            select(visited, vs, pq, j);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> vs(n);
    for (auto& v : vs)
    {
        cin >> v.first >> v.second;
    }

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        vector<pair<int64_t, int64_t>> pq_list;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                pq_list.emplace_back(vs[i].first - vs[j].first, vs[i].second - vs[j].second);
            }
        }

        int min_dist = numeric_limits<int>::max();

        for (auto pq : pq_list)
        {
            int dist = 0;
            vector<bool> visited(n, false);
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    dist++;
                    select(visited, vs, pq, i);
                }
            }
            min_dist = min(min_dist, dist);
        }
        cout << min_dist << endl;
    }
}
