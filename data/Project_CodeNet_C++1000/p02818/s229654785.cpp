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
    long long a, b, k;
    cin >> a >> b >> k;

    if (k > a + b)
        cout << "0 0";
    else if (k > a)
    {
        cout << "0 ";
        k -= a;
        cout << b - k;
    }
    else if (k == a)
    {
        cout << "0 " << b;
    }
    else
        cout << a - k << " " << b;
}