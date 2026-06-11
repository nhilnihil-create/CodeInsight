#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int maxn = 200005;
long long a[maxn], N, K;
bool ok(long long w)
{
    long long sum = 0;
    for (int i = 1; i <= N; i++)
        sum += (a[i] - 1) / w;
    if (sum <= K)
        return 1;
    else
    {
        return 0;
    }
}
int main()
{
    cin >> N >> K;
    long long l = 1, r = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    if (K == 0)
        cout << r << endl;
    else
    {
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (ok(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
}