#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> ap(n), am(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ap[i]);
        am[i] = i - ap[i];
        ap[i] = i + ap[i];
    }
    sort(am.begin(), am.end());
    for (int i = 0; i < n; i++) {
        auto itrl = lower_bound(am.begin(), am.end(), ap[i]),
             itru = upper_bound(am.begin(), am.end(), ap[i]);
        ans += (long long)(itru - itrl);
    }
    cout << ans << endl;
    return 0;
}