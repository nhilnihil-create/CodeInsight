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

int main()
{
    int n;
    cin >> n;

    vector<int64_t> vs(n);
    for (auto& v : vs)
    {
        cin >> v;
    }
    for (int i = 1; i < n; i++)
    {
        vs[i] += vs[i - 1];
    }

    int64_t ans = std::numeric_limits<int64_t>::max();
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, abs(vs[i] - (vs[n - 1] - vs[i])));
    }
    cout << ans << endl;
}
