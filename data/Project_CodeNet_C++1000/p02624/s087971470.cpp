#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    long long a[10000010];
    for (int i = 1; i <= 10000000; i++)
    {
        a[i] = 0;
    }
    for (int i = 1; i <= 10000000; i++)
    {
        for (int j = 1; j <= 10000000; j++)
        {
            if (i * j > 10000000)
            {
                break;
            }
            else
            {
                a[i * j]++;
            }
        }
    }
    long long result = 0;
    for (int i = 1; i <= N; i++)
    {
        result += i * a[i];
    }
    cout << result << endl;
    return 0;
}