#include <iostream>
using namespace std;

int main(void)
{
    int i, j, k, N, K, a[1000], tmp, sum;
    sum = 0;
    cin >> N >> K;
    for (i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (j = 0; j < N; j++)
    {
        for (k = 0; k < j; k++)
        {
            if (a[j] < a[k])
            {
                tmp = a[k];
                a[k] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (i = 0; i < K; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}