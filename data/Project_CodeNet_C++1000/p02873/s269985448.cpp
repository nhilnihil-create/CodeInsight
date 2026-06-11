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
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30));
const long long linf = (1LL<<60);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n+1);
    for(int i=0; i<n; i++)
    {
        if(s[i] == '<') a[i+1] = max(a[i+1], a[i]+1);
    }
    for(int i=n-1; i>=0; i--)
    {
        if(s[i] == '>') a[i] = max(a[i], a[i+1]+1);
    }
    long long ans = 0;
    for(int i=0; i<=n; i++) ans += a[i];
    cout << ans << endl;
    return 0;
}

