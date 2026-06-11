#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, m;
string s;

int main()
{
    cin >> n >> m >> s;

    vector<int> res(0);
    int pos = n;
    
    while(pos > 0)
    {
        int p = 0;
        for (int i = 1; i <= m; i++)
        {
            if(pos - i < 0)
            {
                break;
            }

            if(s[pos - i] == '0')
            {
                p = max(p, i);
            }
        }

        if(p == 0)
        {
            cout << -1 << endl;
            return 0;
        }

        res.emplace_back(p);
        pos -= p;
    }
    
    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ((i == res.size() - 1)? "\n" : " ");
    }

    return 0;
}