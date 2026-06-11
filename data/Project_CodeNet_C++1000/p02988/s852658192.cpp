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

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
        cin >> niz[i];

    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (niz[i] > niz[i - 1] && niz[i] < niz[i + 1] || niz[i] < niz[i - 1] && niz[i] > niz[i + 1])
            cnt++;
    }
    cout << cnt;
}