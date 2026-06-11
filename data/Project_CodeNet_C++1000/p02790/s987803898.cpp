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
    int a, b;
    cin >> a >> b;
    if (a < b || a == b)
    {
        for (int i = 0; i < b; i++)
            cout << a;
    }
    else for (int i = 0; i < a; i++)
        cout << b;
}