#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                string v;
                v.push_back(i + '0'), v.push_back(j + '0'), v.push_back(k + '0');
                int p0 = -1, p1 = -1, p2 = -1;
                for (int idx = 0; idx < s.size(); ++idx)
                {
                    if (s[idx] == v[0] && p0 == -1)
                    {
                        p0 = idx;
                        continue;
                    }
                    else if (s[idx] == v[1] && p0 >= 0 && p1 == -1)
                    {
                        p1 = idx;
                        continue;
                    }
                    else if (s[idx] == v[2] && p1 >= 0)
                    {
                        p2 = idx;
                        continue;
                    }
                }
                if (p0 >= 0 && p1 > p0 && p2 > p1)
                {
                    //cout << s[p0] << s[p1] << s[p2] << endl;
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
