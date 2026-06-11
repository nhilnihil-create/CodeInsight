#include <iostream>
#include <string>

using namespace std;

const int NMAX = 1e6;

int N;
string s;

int v[NMAX + 2];
bool hasOne;

int GETP2(int nr)
{
    int ans = 0;

    while(nr % 2 == 0)
    {
        ans++;
        nr /= 2;
    }

    return ans;
}

bool GetParity() ///0->even, 1->odd
{
    ///C(N, K) = N * (N - 1) * (N - 2) * ... * (N - K + 1)
    ///        / 1 *    2    *    3    * ... *      K

    ///C(N, K + 1) = asBefore * (N - K) / (K + 1)

    long long nrPow2 = 0;

    int ans = 0;

    for(int i = 1; i <= N / 2; i++) ///C(N - 1, i - 1)
    {
        if(v[i] % 2 == 1)
        {
            if(nrPow2 == 0)
                ans++;
        }

        if(v[N - i + 1] % 2 == 1)
        {
            if(nrPow2 == 0)
                ans++;
        }

        nrPow2 += GETP2(N - i);
        nrPow2 -= GETP2(i);
    }

    if(N % 2 == 1)
    {
        if(v[N / 2 + 1] % 2 == 1)
        {
            if(nrPow2 == 0)
                ans++;
        }
    }

    return (ans % 2 == 1);
}

int main()
{
    cin >> N >> s;

    for(int i = 1; i <= N; i++)
    {
        v[i] = s[i - 1] - '1';
        if(v[i] == 1)
            hasOne = true;
    }

    bool parity = GetParity();

    if(parity == 1)
        cout << 1 << '\n';
    else
    {
        if(hasOne == 1)
            cout << 0 << '\n';
        else
        {
            for(int i = 1; i <= N; i++)
                v[i] /= 2;

            parity = GetParity();

            cout << 2 * parity << '\n';
        }
    }

    return 0;
}
