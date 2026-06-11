#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    long long int i, j, count;
    count = T.size();
    for (i = 0; i <= S.size() - T.size(); i++)
    {
        long long int zantei = 0;
        for (j = 0; j < T.size(); j++)
        {
            if (S[i + j] != T[j])
            {
                zantei += 1;
            }
        }
        if (zantei < count)
        {
            count = zantei;
        }
    }
    cout << count << endl;
    return 0;
}