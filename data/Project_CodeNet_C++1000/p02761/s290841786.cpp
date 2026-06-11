#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
using namespace std;
typedef long long int lli;
int main(void)
{
    int N, M;
    cin >> N >> M;
    string s;
    int tmp1, tmp2;
    vector<int> x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp1 >> tmp2;
        x.push_back(tmp1);
        y.push_back(tmp2);
    }
    if (M > 0)
    {
        for (int i = 0; i < 1000; i++)
        {
            s = to_string(i);
            for (int k = 0; k < M; k++)
            {
                if (s[x[k] - 1] - '0' == y[k])
                {
                    /*if (k == M - 1 && (int)(log10(i) + 1) == N)
                {
                    cout << i << endl;
                    return 0;
                }*/
                    if ((N == 3 && s[0] - '0' != 0 && (int)(log10(i) + 1) == N && k == M - 1) || (N == 2 && k == M - 1 && (int)(log10(i) + 1) == N) || (N == 1 && k == M - 1))
                    {
                        cout << i << endl;
                        return 0;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    else
    {
        if (N == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        else if (N == 2)
        {
            cout << 10 << endl;
            return 0;
        }
        else
        {
            cout << 100 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}