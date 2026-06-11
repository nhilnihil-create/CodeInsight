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
    int h, n;
    cin >> h >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        niz[i] = x;
    }
    for (auto x : niz)
    {
        h -= x;
        if (h <= 0)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}