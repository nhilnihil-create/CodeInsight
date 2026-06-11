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
    uint64_t n;
    cin >> n;
    map<uint64_t, uint64_t> count;
    for (int i = 0; i < n; i++)
    {
        uint64_t a;
        cin >> a;
        count[a]++;
    }

    auto check = [](uint64_t n, map<uint64_t, uint64_t> count) -> bool {
        if (count[0] == n)
        {
            return true;
        }
        if (n % 3 != 0)
        {
            return false;
        }
        vector<uint64_t> buf;
        for (auto elem : count)
        {
            for (int i = 0; i < elem.second / (n / 3); i++)
            {
                buf.push_back(elem.first);
            }
        }
        if (buf.size() != 3)
        {
            return false;
        }
        return (buf[0] ^ buf[1] ^ buf[2]) == 0;
    };

    cout << (check(n, count) ? "Yes" : "No") << endl;
}
