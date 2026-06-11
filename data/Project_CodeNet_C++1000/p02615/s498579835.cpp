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
long long  a[200005];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n, cmp);
    sum = a[0];
    for (int i = 1; i < n / 2; ++i)
    {
        sum += 2 * a[i];
    }
    if (n & 1)
        sum += a[n / 2];
    printf("%lld\n", sum);
}