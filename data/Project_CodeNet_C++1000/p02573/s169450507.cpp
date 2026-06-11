#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N, M, i, A, B, A_top, B_top;
    cin >> N >> M;
    vector<long long int> group(N + 1); //1 kara N, minus is next
    for (i = 1; i <= N; i++)
    {
        group[i] = 1;
    }
    for (i = 0; i < M; i++)
    {
        cin >> A >> B;
        A_top = A;
        B_top = B;
        while (group[A_top] < 0)
        {
            A_top = group[A_top] * (-1);
        }
        while (group[B_top] < 0)
        {
            B_top = group[B_top] * (-1);
        }
        if (A_top != B_top)
        {
            if (group[A_top] < group[B_top])
            {
                group[B_top] += group[A_top];
                group[A_top] = B_top * (-1);
            }
            else
            {
                group[A_top] += group[B_top];
                group[B_top] = A_top * (-1);
            }
        }
    }
    long long int result = 1;
    for (i = 1; i <= N; i++)
    {
        if (group[i] > result)
        {
            result = group[i];
        }
    }
    cout << result << endl;
    return 0;
}