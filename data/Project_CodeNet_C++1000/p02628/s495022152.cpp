# include <iostream>

using namespace std;


int main()
{
    int N, K;

    cin >> N >> K;

    int* p;
    p = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    int sum = 0;
    int help;

    if (N == K)
    {
        for (int i = 0; i < N; i++)
        {
            sum += p[i];
        }
    }
    else
    {
        for (int i = 0; i < K; i++)
        {
            for (int i = 0; i < N; i++)
            {
                if (i < N - 1)
                {
                    if (p[i] < p[i + 1])
                    {
                        help = p[i];
                        p[i] = p[i + 1];
                        p[i + 1] = help;
                    }
                }
                if (i == N - 1)
                {
                    sum += p[i];
                }
            }
            N--;
        }
    }
    cout << sum;


    return 0;
}