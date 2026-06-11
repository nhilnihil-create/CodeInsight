#include<bits/stdc++.h>
using namespace std;

long long mod = 2019;

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
    string S;
    cin >> S;
    vector<long long> count(2019);
    for (long long i = 0; i < 2019; i++)
    {
        count[i] = 0;
    }

    count[0]++;
    long long pre = 0;

    for (long long i = S.size() - 1; i > -1; i--)
    {
        pre = ((S[i]-'0') * power(10, S.size() - 1 - i) + pre) % mod; 
        count[pre]++;
    }

    long long ans = 0;

    for (long long i = 0; i < 2019; i++)
    {
        ans += count[i] * (count[i] - 1) / 2;
    }
    cout << ans << endl;
}