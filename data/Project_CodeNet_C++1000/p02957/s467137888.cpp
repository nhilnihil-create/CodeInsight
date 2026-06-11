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
    long long a, b;
    cin >> a >> b;

    double res = (double)(a + b) / 2;

    if (res == floor(double(res)))
        cout << fixed << (long long)res;
    else cout << "IMPOSSIBLE";
}