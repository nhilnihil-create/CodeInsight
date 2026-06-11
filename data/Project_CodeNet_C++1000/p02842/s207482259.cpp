#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 1; i <= 50000; i++)
    {
        if (floor(i * 1.08) == n)
        {
            ans = i;
            break;
        }
    }

    if(ans == -1) {
        cout << ":(" << endl;
    } else {
        cout << ans << endl;
    }
}

int main()
{
    solve1();
}
