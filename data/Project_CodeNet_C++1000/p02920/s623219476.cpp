#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

class BinaryIndexedTree
{
    vector<int64_t> container;

public:
    BinaryIndexedTree(size_t size)
        : container(size + 1)
    {
        fill(container.begin(), container.end(), 0);
    }
    void add(size_t i, int64_t v)
    {
        size_t idx = i + 1;
        while (idx < container.size())
        {
            container[idx] += v;
            idx += idx & -idx;
        }
    }
    int64_t find(size_t i)
    {
        size_t idx = i;

        int64_t result = 0;
        while (idx != 0)
        {
            result = container[idx] + result;
            idx -= idx & -idx;
        }
        return result;
    }
    size_t lower_bound(int64_t v)
    {
        if (v == 0)
        {
            return 0;
        }
        int64_t w = v;
        size_t x = 0;
        for (size_t k = msb(container.size() - 1); k > 0; k >>= 1)
        {
            if (x + k < container.size() && container[x + k] < w)
            {
                w -= container[x + k];
                x += k;
            }
        }
        return x + 1;
    }

private:
    size_t msb(size_t x)
    {
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return (x + 1) >> 1;
    }
};

int main()
{
    int n;
    cin >> n;

    multiset<int> s;
    rep(i, 1 << n)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    vector<int> curr;
    curr.push_back(*prev(s.end()));
    s.erase(prev(s.end()));

    while (!s.empty())
    {
        int size = curr.size();
        rep(i, size)
        {
            auto it = s.lower_bound(curr[i]);
            if (it == s.begin())
            {
                cout << "No" << endl;
                return 0;
            }
            else
            {
                it--;
                curr.push_back(*it);
                s.erase(it);
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}