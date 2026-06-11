#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    string S;
    cin >> S;
    vector<long long> preans(10);
    long long ans = 0;
    for(long long i = 0; i < 10; i++)
    {
        for (long long j = 0; j < 10; j++)
        {
            for (long long k = 0; k < 10; k++)
            {
                preans[k] = 0;
            }
            long long count = 0;
            for (long long k = 0; k < N; k++)
            {
                if (count == 0)
                {
                    if (S[k] - '0' == i)
                    {
                        count++;
                    }
                }
                else if (count == 1)
                {
                    if (S[k] - '0' == j)
                    {
                        count++;
                    }
                }
                else if (count == 2)
                {
                    preans[S[k] - '0']++;
                }
            }
            for (long long k = 0; k < 10; k++)
            {
                if (preans[k] > 0)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}