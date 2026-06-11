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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> memo(n);
    int m = 0;
    for (int i = n; i > 0; i--)
    {
        int sum = 0;
        for (int j = i; j <= n; j += i)
        {
            sum += memo[j - 1];
        }
        bool flag1 = sum % 2 == 0;
        bool flag2 = a[i - 1] == 0;
        if (flag1 ^ flag2)
        {
            memo[i - 1] = 1;
            m++;
        }
    }
    cout << m << endl;
    for (int i = 0; i < n; i++)
    {
        if (memo[i] == 0)
            continue;
        cout << i + 1 << " ";
    }
    return 0;
}