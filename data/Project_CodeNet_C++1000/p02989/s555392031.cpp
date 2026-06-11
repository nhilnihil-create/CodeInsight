#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];

    sort(d.begin(), d.end());
    int idx = (n - 1)/ 2;
    int left = d[idx];
    int right = d[idx + 1];
    int ans = right - left;
    cout << ans << endl;
    return 0;
}
