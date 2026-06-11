#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N;
string S;

signed main()
{
    cin >> N;
    cin >> S;

    int ans = 0;
    rep(i,1000)
    {
        int mem = 1;
        rep(j,N)
        {
            if('0' + ((i / mem) % 10) == S[j])
            {
                mem *= 10;
                if(mem == 1000)
                {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}