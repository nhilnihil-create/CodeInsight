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
    int n, k;
    cin >> n >> k;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
        cin >> niz[i];

    sort(niz.begin(), niz.end(), greater<int>());
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (k > 0)
        {
            k--;
            continue;
        }
        else if (niz[i] > 0)
                cnt += niz[i];
    }
    cout << cnt;
}