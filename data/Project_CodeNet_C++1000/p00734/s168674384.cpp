#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

using ll = long long;
int N, M;
vector<int> Sh, St;
int sumH;
int sumT;

bool solve()
{
    for (int i = 0; i < M; ++i)
    {
        int xH = sumH - Sh[i];
        for (int j = 0; j < N; ++j)
        {
            int xT = sumT - St[j] + Sh[i];
            xH += St[j];
            if (xH == xT)
            {
                cout << St[j] << " " << Sh[i] << endl;
                return true;
            }
            xH -= St[j];
            
        }
    }
    return false;
}
int main(void)
{
    while (1)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        St.resize(N);
        Sh.resize(M);

        for (int i = 0; i < N; ++i)
        {
            cin >> St[i];
        }
        for (int i = 0; i < M; ++i)
        {
            cin >> Sh[i];
        }
        sumH = accumulate(Sh.begin(), Sh.end(), 0);
        sumT = accumulate(St.begin(), St.end(), 0);
        if (!solve())
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
