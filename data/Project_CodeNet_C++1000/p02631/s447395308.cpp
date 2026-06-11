#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

int main()
{
    size_t N;
    cin >> N;
    vector<int> a(N);
    using bitarr = array<uint32_t, 30>;
    bitarr bits = {};
    vector<bitarr> b(a.size());
    for (uint32_t i = 0; i < N; ++i)
    {
        cin >> a[i];
        for (uint32_t k = 0; k < 30; ++k)
        {
            int x = (a[i] & 1 << k) >> k;
            b[i][k] = x;
            bits[k] += x;
        }
    }
    for (uint32_t i = 0; i < N; ++i)
    {
        int y = 0;
        for (uint32_t k = 0; k < 30; ++k)
        {
            y += ((bits[k] - b[i][k]) % 2) * (1 << k);
        }
        cout << y << " ";
    }
    return 0;
}