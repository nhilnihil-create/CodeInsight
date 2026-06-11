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
    int m, d;
    cin >> m >> d;

    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            const int d0 = j % 10;
            const int d10 = j / 10;
            if (d0 >= 2 && d10 >= 2 && d0 * d10 == i)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}
