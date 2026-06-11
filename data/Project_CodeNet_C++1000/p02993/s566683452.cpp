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

    for (int i = 0; i < str.length() - 1; i++)
        if (str[i] == str[i + 1])
        {
            cout << "Bad";
            return 0;
        }
    cout << "Good";
}