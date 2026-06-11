#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int i = 0, j = N - 1, p = 0;
    while (i < j)
    {
        while (S[i] != 'W' && i < N)
        {
            i++;
        }
        while (S[j] != 'R' && j > 0)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(S[i], S[j]);
        p++;
    }
    cout << p << endl;
}