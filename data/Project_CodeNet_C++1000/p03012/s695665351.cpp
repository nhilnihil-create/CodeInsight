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

    int min = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int first_sum = 0, second_sum = 0;
        for (int k = 0; k < i + 1; k++)
        {
            first_sum += niz[k];
        }
        for (int j = i + 1; j < n; j++)
        {
            second_sum += niz[j];
        }
        int x = abs(first_sum - second_sum);
        if (x < min)
            min = x;
    }
    cout << min;
}