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
    
    while(pos)
    {
        for (int i = m; i >= 1; i--)
        {
            if(pos - i < 0) continue;

            if(s[pos - i] == '0')
            {
                res.emplace_back(i);
                pos -= i;
                break;
            }
            
            if(i == 1)
            {
               cout << -1 << endl;
               return 0;
            }
        }
    }

    for(int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << ((i == 0)? "\n" : " ");
    }

    return 0;
}