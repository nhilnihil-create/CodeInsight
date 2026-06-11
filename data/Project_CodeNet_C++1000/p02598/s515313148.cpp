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
    int n, k;
    cin >> n >> k;
    int a[200000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = MOD;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += a[i] / mid;
            if (a[i] % mid == 0)
                cnt--;
        }
        if (cnt <= k)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << endl;
}