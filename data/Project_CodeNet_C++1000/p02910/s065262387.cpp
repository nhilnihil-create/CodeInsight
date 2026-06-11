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
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (str[i] != 'R' && str[i] != 'D' && str[i] != 'U')
            {
                cout << "No";
                return 0;
            }
        }
        else if (str[i] != 'L' && str[i] != 'U' && str[i] != 'D')
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}