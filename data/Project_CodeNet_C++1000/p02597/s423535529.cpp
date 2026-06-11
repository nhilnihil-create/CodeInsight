#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string c;
    cin >> c;
    string d;
    d = c;
    sort(c.begin(), c.end());
    int diff = 0;
    for (int i = 0; i < N; i++)
    {
        if (c[i] != d[i])
            diff++;
    }
    cout << diff / 2 << endl;
}