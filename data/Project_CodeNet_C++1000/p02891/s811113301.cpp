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
    ll K;
    cin >> S;
    cin >> K;
    ll n = S.size();

    bool flag = true;
    REP(i, n - 1)
    {
        if (S[i] != S[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        ll count = n * K;
        cout << count / 2 << endl;
        return 0;
    }

    ll countMono = 0;
    ll countSame = 1;
    for (ll i = 0; i < n - 1; ++i)
    {
        if (S[i] == S[i + 1])
        {
            countSame++;
        }
        else
        {
            countMono += countSame / 2;
            countSame = 1;
        }
    }
    countMono += countSame / 2;

    ll ans = 0;
    if (S[0] != S[n - 1])
    {
        ans = countMono * K;
    }
    else
    {
        ll countSameHead = 1;
        for (ll i = 0; i < n - 1; ++i)
        {
            if (S[i] == S[i + 1])
            {
                countSameHead++;
            }
            else
            {
                break;
            }
        }
        ll countSameTail = 1;
        for (ll i = n - 1; n > 1; --i)
        {
            if (S[i] == S[i - 1])
            {
                countSameTail++;
            }
            else
            {
                break;
            }
        }
        ans = countMono * K;
        ans -= (countSameHead / 2 + countSameTail / 2 - (countSameHead + countSameTail) / 2) * (K - 1);
    }
    

    cout << ans << endl;
}
