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
    int n, m;
    cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }

    if (sum > n)
        cout << "-1";
    else cout << n-sum;
}