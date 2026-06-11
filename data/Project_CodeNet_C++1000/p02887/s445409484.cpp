#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int res = 1;
    for (int i = 1; i < N; i++)
    {
        if (S.at(i) != S.at(i - 1))
            res++;
    }
    cout << res << endl;
    return 0;
}
