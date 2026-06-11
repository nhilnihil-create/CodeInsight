#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int p[N];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    int a;
    for (int i = 1; i < N; i++)
    {
        for (int i = 1; i < N; i++)
        {
            if (p[i] < p[i - 1])
            {
                a = p[i];
                p[i] = p[i - 1];
                p[i - 1] = a;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < K; i++)
    {
        answer += p[i];
    }

    cout << answer << endl;
}