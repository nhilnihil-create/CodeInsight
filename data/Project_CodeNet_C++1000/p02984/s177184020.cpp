#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> ans(n);
    int index = 1;
    int cnt = 0;
    ll temp = sum;
    while (cnt < n / 2)
    {
        temp -= 2 * a[index];
        cnt++;
        index += 2;
        index %= n;
    }
    ans[0] = temp;
    for (int i = 1; i < n; i++)
    {
        ans[i] = 2 * a[i - 1] - ans[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}