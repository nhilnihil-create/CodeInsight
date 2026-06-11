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
    string s;
    cin >> n >> m >> s;
    vector<int> dp(n+1, inf);
    dp[n] = 0;
    queue<int> q;
    q.push(0);
    for(int i=n-1; i>=0; i--)
    {
        while(1)
        {
            if(q.size() == 0)
            {
                cout << "-1" << endl;
                return 0;
            }
            if(q.front()!=inf && q.size()<=m) break;
            q.pop();
        }
        if(s[i]=='0') dp[i] = q.front()+1;
        q.push(dp[i]);
    }
    vector<int> ans;
    int x = 0;
    int rest = dp[0];
    while(x<n)
    {
        rest--;
        int i=1;
        while(dp[x+i] != rest) i++;
        ans.push_back(i);
        x += i;
    }
    for(int i=0; i<ans.size(); i++) printf("%d%c", ans[i], i==int(ans.size())-1?'\n':' ');
    return 0;
}
