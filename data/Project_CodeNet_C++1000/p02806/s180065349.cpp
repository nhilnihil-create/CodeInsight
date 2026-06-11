#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> T(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i] >> T[i];
    }
    string X;
    cin >> X;
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == X)
        {
            index = i + 1;
            break;
        }
    }
    cout << accumulate(T.begin() + index, T.end(), 0) << endl;

    return 0;
}