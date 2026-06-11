#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            bitset<16> a(i);
            bitset<16> b(j);
            for (int k = 0; k < 16; k++)
            {
                if (a[k] != b[k])
                {
                    cout << k + 1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}
