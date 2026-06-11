#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define input(str) cin >> str;
#define output(str) cout << str << endl;

int main()
{
    double N, T;
    input(N)
    T = 1.08;

    double A = N / T;

    int Ah = ceil(A) * T;
    int Al = floor(A) * T;

    if (Ah == N || Al == N)
    {
        int C = (Ah == N) ? ceil(A) : (Al == N) ? floor(A) : 0;
        output(C)
    }
    else
    {
        output(":(")
    }
}