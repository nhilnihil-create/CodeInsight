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

    sort(str.begin(), str.end());
    if (str[0] == str[1] && str[2] == str[3])
    {
        if (str[0] != str[2] && str[1] != str[3])
            cout << "Yes";
        else cout << "No";
    }
    else cout << "No";
}