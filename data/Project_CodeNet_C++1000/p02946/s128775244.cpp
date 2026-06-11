#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
#include <map>
#include <set>

const int INT_INF = 1e9;
const long long LONG_INF = 1e18;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

using namespace std;

int main()
{
    int k, x;
    cin >> k >> x;
    int start, end;
    start = max(x - k + 1, -1000000);
    end = min(x + k - 1, 1000000);
    cout << start;
    for (int i = start + 1; i <= end; i++)
    {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}