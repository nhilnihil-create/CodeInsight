# include <iostream>
# include <math.h>

using namespace std;

int main()
{
    int N, D;

    cin >> N >> D;

    int* X, * Y;
    X = new int[N];
    Y = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
    }

    int close = 0;

    sqrt(double(N));

    for (int i = 0; i < N; i++)
    {
        if (sqrt(pow(double(X[i]),2) + pow(double(Y[i]),2)) <= D)
        {
            close++;
        }
    }
    cout << close;


    return 0;
}