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
    int n;
    string str;
    cin >> n >> str;

    int ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] != str[i + 1])
            ans++;
    }
    cout << ans;
}