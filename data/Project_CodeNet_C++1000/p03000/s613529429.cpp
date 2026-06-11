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
    int n, x;
    cin >> n >> x;

    vector<int> niz(n);
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
        sum += niz[i];
        if (sum <= x)
            cnt++;
    }
    cout << cnt;
}