#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    string C;
    cin >> C;

    // count num of R
    int R_num = 0;
    for (int i = 0; i < N; i++)
    {
        if (C[i] == 'R')
        {
            R_num++;
        }
    }

    int res = 0;
    for (int i = 0; i < R_num; i++)
    {
        if (C[i] == 'W')
        {
            res++;
        }
    }

    cout << res << endl;
}
