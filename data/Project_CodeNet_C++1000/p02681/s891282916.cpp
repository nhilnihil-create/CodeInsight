#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <map>
#include <utility>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < t.size() - 1; i++)
    {
        if (s[i] != t[i])
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}