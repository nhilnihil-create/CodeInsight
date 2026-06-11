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

    vector<int> niz2(niz);
    sort(niz2.begin(), niz2.end());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (niz[i] != niz2[i])
            cnt++;
        if (cnt > 2)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}