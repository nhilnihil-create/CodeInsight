#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int m;
    cin >> m;

    vector<int64_t> ds(m), cs(m);
    int64_t sum = 0;
    int64_t ans = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> ds[i] >> cs[i];
        sum += ds[i] * cs[i];
        ans += cs[i];
    }
    ans--;
    ans += (sum - 1) / 9;

    cout << ans << endl;
}
