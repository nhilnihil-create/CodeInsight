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
    int max = INT_MIN, max_idx = -1;
    int max2 = INT_MIN, max2_idx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
        if (niz[i] > max)
        {
            max = niz[i];
            max_idx = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (niz[i] > max2 && i != max_idx)
        {
            max2 = niz[i];
            max2_idx = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != max_idx)
            cout << niz[max_idx] << endl;
        else cout << niz[max2_idx] << endl;
    }
}