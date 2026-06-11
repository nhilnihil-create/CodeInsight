#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long power(long long x, long long y)
{
    long long ret = 1;
    while(y > 0)
    {
        if (y & 1)
        {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

int main(void)
{
    long long N;
    cin >> N;

    vector<long long> vec(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> vec[i];
    } 

    long long ans = 0;
    long long pw = 0;
    while(1)
    {
        for (long long i = 0; i < N; i++)
        {
            if (vec[i] != 0)
            {
                break;
            }
            if (i == N - 1)
            {
                cout << ans << endl;
                exit(0);
            }
        }

        long long cnt = 0;
        for (long long i = 0; i < N; i++)
        {
            if (vec[i] & 1)
            {
                cnt ++;
            }
        }
        ans += (((cnt * (N - cnt)) % mod) * power(2, pw)) % mod;
        ans = ans % mod;
        pw ++;
        for (long long i = 0; i < N; i++)
        {
            vec[i] >>= 1;
        }
    }
}