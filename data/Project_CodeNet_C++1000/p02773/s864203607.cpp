#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> M;
    for (int i = 0; i < N; ++i)
    {
        string S;
        cin >> S;
        M[S]++;
    }

    // 最大の書かれた回数
    int writtenTimeMax = 0;
    for (auto &e : M)
    {
        if (writtenTimeMax < e.second)
            writtenTimeMax = e.second;
    }

    for (auto &e : M)
    {
        if (writtenTimeMax == e.second)
            cout << e.first << endl;
    }

    return 0;
}
