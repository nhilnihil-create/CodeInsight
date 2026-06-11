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

    vector<int> niz(n), res(n);
    for (int i = 0; i < n; i++)
        cin >> niz[i];

    for (int i = 0; i < n; i++)
    {
        res[niz[i] - 1] = i + 1;
    }
    for (auto x : res)
        cout << x << " ";
}