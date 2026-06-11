#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;

    vector<vector<long long>> vec(10, vector<long long>(10));

    for (long long i = 1; i <= 9; i++)
    {
        for (long long j = 1; j <= 9; j++)
        {
            long long res = 0;
            for (long long k = 1; k <= N; k++)
            {
                if (k % 10 == i)
                {
                    long long l = k;
                    while(1)
                    {
                        if (l / 10 == 0)
                        {
                            break;
                        }
                        l = l / 10;
                    }

                    if (l % 10 == j)
                    {
                        res++;
                    }
                }
            }
            vec.at(i).at(j) = res;
        }
    }

    long long ans = 0;
    for (long long i = 1; i < 10; i++)
    {
        for (long long j = 1; j < 10; j++)
        {
            ans += vec.at(i).at(j) * vec.at(j).at(i);
        }
    }
    cout << ans << endl;
}