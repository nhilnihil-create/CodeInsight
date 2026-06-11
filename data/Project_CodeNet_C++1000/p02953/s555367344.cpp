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

    for (int i = n - 1; i > 0; i--)
    {
        if (niz[i] >= niz[i - 1])
            continue;
        else if (niz[i] + 1 == niz[i - 1])
            --niz[i - 1];
        else
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}