#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007

int main()
{
    long long int n;
    cin >> n;
    long long int ans = 0;
    for (long long int i = 1; i <= n; i++)
    {
        ans += i * (n - i + 1);
    }
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        ans -= u * (n - v + 1);
    }
    cout << ans << endl;
}