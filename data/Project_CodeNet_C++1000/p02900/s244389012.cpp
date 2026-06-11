#include<bits/stdc++.h>
using namespace std;

vector<long long> pf (long long n)
{
    vector<int> cnt((long long)pow(n, 0.5) + 1);
    for (long long i = 0; i < cnt.size(); i++)
    {
        cnt[i] = 0;
    }
    vector<long long> res;
    res.push_back(1);
    for (long long i = 2; i <= (long long)pow(n, 0.5); i++)
    {
        while(1)
        {
            if (n % i == 0)
            {
                if (cnt[i] == 0)
                {
                    res.push_back(i);
                    cnt[i] =1;
                }
                n = n / i;
            }
            else
            {
                break;
            }
        }
    }
    if (n != 1)
    {
        res.push_back(n);
    }
    return res;
}

int main(void)
{
    long long A, B;
    cin >> A >> B;
    long long minnum = min(A, B);
    long long ans = 0;
    vector<long long> a = pf(A);
    vector<long long> b = pf(B);
    for (long long i = 0; i < a.size(); i++)
    {
        for (long long j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}