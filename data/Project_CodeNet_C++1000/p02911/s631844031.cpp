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

int lower[100001];

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> points(n, k-q);

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        points[x-1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (points[i] > 0)
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}