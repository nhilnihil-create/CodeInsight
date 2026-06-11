#include <iostream>
using namespace std;

int main(void)
{
    int N, K, i, j, k, count;
    count = 0;
    int d[100] = {0};
    int A[100] = {0};

    cin >> N;
    cin >> K;
    for (j = 0; j < K; j++)
    {
        cin >> d[j];
        for (i = 0; i < d[j]; i++)
        {
            cin >> k;
            A[k - 1]++;
        }
    }

    for (j = 0; j < N; j++)
    {
        if (A[j] == 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}