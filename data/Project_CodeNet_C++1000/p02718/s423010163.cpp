#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if (4 * a[n - m] * m < sum) cout << "No" << endl;
    else cout << "Yes" << endl;
}