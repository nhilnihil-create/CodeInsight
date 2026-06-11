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
    int64_t a, b, c;
    cin >> a >> b >> c;

    // sqrt(a) + sqrt(b) < sqrt(c)
    // a + b + 2 * sqrt(ab) < c
    // 2 * sqrt(ab) < c - a - b
    // 4 * ab < (c - a - b) ^2

    if (c < a + b)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << (4ll * a * b < (c - a - b) * (c - a - b) ? "Yes" : "No") << endl;
    }
}
