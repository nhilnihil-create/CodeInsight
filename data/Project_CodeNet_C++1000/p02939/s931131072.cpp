#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;
    ll n = S.size();
    ll ans = 1;
    ll pos = 0;
    bool flag = false;
    while(pos < n)
    {
        if (flag)
        {
            if (pos + 1 < n)
            {
                ans++;
            }
            flag = false;
        }
        else
        {
            if (pos + 1 < n)
            {
                if (S[pos] == S[pos + 1])
                {
                    if (pos + 2 < n)
                    {
                        flag = true;
                        ans++;
                        pos++;
                    }
                }
                else
                {
                    ans++;
                }
            }
        }
        pos++;
    }

    cout << ans << endl;
}
