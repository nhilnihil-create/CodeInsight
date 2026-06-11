#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

int K;
string S;

void inc()
{
    int N = S.size() - 1;
    for(int i = N; i >= 0; i--)
    {
        int now = S[i] - '0';
        if(i == 0)
        {
            S.clear();
            if(now == 9)
            {
                S.push_back('1');
                for(int j = 0; j < N + 1; j++)
                    S.push_back(max((char)(S[j] - 1), '0'));
            }
            else
            {
                S.push_back(now + 1 + '0');
                for(int j = 0; j < N; j++)
                    S.push_back(max((char)(S[j] - 1), '0'));
            }
            return;
        }

        int pre = S[i - 1] - '0';
        if(now != 9 && pre >= now)
        {
            S[i]++;
            for(int j = i + 1; j <= N; j++)
            {
                S[j] = max((char)(S[j - 1] - 1), '0');
            }
            return;
        }
    }
}

signed main()
{
    cin >> K;

    S = "1";
    rep(i, K - 1)
    {
        // cout << S << endl;
        inc();
    }

    cout << S << endl;

    return 0;
}
