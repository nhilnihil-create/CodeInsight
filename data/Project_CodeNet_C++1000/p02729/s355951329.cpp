#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
typedef long long ll;
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += (n - i - 1);
    }
    for (int i = 0; i < m; ++i)
    {
        sum += (m - i - 1);
    }
    cout << sum << endl;
    return 0;
}
