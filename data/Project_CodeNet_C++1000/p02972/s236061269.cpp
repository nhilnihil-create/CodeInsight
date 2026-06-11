#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;

    vector<long long> a(N + 1);
    for (long long i = 1; i < N + 1; i++)
    {
        cin >> a[i];
    }
    vector<long long> ans(N+1);
    long long M = 0;
    for (long long i = N; i > 0; i--)
    {
        long long sum = 0;
        for (long long j = 2; j <= N / i; j++)
        {
            sum += ans[i * j];
        }
        ans[i] = abs((sum % 2) - a[i]);
        if (ans[i] == 1)
        {
            M++;
        }
    }
    cout << M << endl;
    if (M !=0)
    {
        for (long long i = 1; i < N+1; i++)
        {
            if (ans[i] == 1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}