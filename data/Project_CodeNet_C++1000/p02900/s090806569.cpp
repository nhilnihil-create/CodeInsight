#include <bits/stdc++.h>
#define int long long
using namespace std;
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
void factor(int n, vector<int> &x)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            x.push_back(i);
            if (i * i != n)
                x.push_back(n / i);
        }
    }
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    factor(n, a);
    factor(m, b);
    set<int> s1;
    for (auto &i : a)
        s1.insert(i);
    set<int> s;
    for (auto &i : b)
        if (s1.count(i))
            s.insert(i);
    vector<int> x;
    for (auto &i : s)
        x.push_back(i);
    set<int> ans;
    for (auto &y : x)
    {
        if (y == 1)
        {
            ans.insert(y);
            continue;
        }
        for(int i = 1; i * i <= y; i++)
        {
            if(i==1)
                continue;
            if (y % i == 0)
            {
                if(ans.count(i))
                    goto lb;
                if (i * i != y)
                    if(ans.count(i))
                        goto lb;
            }
        }
        ans.insert(y);
        lb:;
    }
    cout << ans.size();
    return 0;
}
//16:33