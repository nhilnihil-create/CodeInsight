#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

long long mod = 1000000007;

void dfs(int p, int prev, vector<int> &a, vector<int> &dp, int dpl, vector<vector<int>> &v, vector<int> &res)
{
    int l = -1, r = dpl, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (dp[mid] >= a[p])
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    int temp = dp[r];
    dp[r] = a[p];
    if (temp == -1)
    {
        dpl++;
    }
    res[p] = dpl;
    for (int i = 0; i < v[p].size(); i++)
    {
        if (v[p][i] == prev)
        {
            continue;
        }
        dfs(v[p][i], p, a, dp, dpl, v, res);
    }
    dp[r] = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");
    
    
    // int t;
    // cin >> t;
    // for (int qwe = 0; qwe < t; qwe++)
    // {
    //     cout << "Case #" << qwe + 1 << ": ";
    // }


    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        mp[a[i] + a[0] - i]++;
    }
    long long rez = mp[0];
    int curr = 0;
    for (int i = 1; i < n; i++)
    {
        curr = a[0] - a[i] - i;
        mp[a[i] + a[0] - i]--;
        rez += mp[curr];
    }
    cout << rez << '\n';


    return 0;
}
