# include <iostream>
# include <math.h>

using namespace std;


int main()
{
    int X, N;

    cin >> X >> N;

    int* p;
    p = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }
    bool found = true;
    int output = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i] == X)
        {
            found = true;
            i = N;
        }
        else
        {
            found = false;
            output = X;
        }
    }

    if (N == 0)
    {
        found = false;
        output = X;
    }

    int j = 1;
    while (found)
    {
        for (int i = 0; i < N; i++)
        {
            if (p[i] == X-j)
            {
                found = true;
                i = N;
            }
            else
            {
                found = false;
                output = X - j;
            }
        }

        if (found)
        {
            for (int i = 0; i < N; i++)
            {
                if (p[i] == X + j)
                {
                    found = true;
                    i = N;
                }
                else
                {
                    found = false;
                    output = X + j;
                }
            }
        }
        j++;
    }
    cout << output;

    return 0;
}