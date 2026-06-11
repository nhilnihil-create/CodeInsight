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
    cin >> n;

    int cnt = 0, curr = 1;

    while (curr <= n)
    {
        if (string(to_string(curr)).length() % 2)
            cnt++;
        curr++;
    }

    cout << cnt;
}