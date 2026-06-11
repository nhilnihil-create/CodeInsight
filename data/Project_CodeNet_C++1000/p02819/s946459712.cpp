#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int a, flag;

    cin >> a;

    while (1)
    {
        for (int i = a; i <= INT_MAX; i++)
        {
            if (i == 1 || i == 0)
                continue;

            flag = 1;

            for (int j = 2; j <= i / 2; ++j)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                cout << i;
                return 0;
            }
        }
    }
}