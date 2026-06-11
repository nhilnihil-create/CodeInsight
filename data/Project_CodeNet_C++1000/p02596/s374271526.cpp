#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> a(1000001);

int main()
{
    int N;
    cin >> N;
    a[1] = 7 % N;
    for (int i = 2; i <= N; i++) a[i] = (a[i - 1] * 10 + 7) % N;

    for (int i = 1; i <= N; i++)
    {
        if (a[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}