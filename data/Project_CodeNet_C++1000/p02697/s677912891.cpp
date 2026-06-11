#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#include <tuple>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << x << endl
// #define int long long 

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30)-1);
const ll linf = (1LL<<60);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int> > ans;
    if(n%2)
    {
        for(int l=1, r=n-1; l<r; l++, r--)
        {
            ans.emplace_back(l,r);
        }
    }
    else
    {
        bool flag = false;
        for(int l=1, r=n-1; l<r; l++, r--)
        {
            if(!flag && r-l <= n/2)
            {
                r--;
                flag = true;
            }
            ans.emplace_back(l,r);
        }
    }
    for(int i=0; i<m; i++)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}