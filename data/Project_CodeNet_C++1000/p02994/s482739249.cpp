#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, L;
    cin >> N >> L;
    int aji[N];
    int min_aji = abs(L);
    int aji1 = L;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        aji[i] = L + i;
        if (min_aji > abs(aji[i]))
        {
            min_aji = abs(aji[i]);
            aji1 = aji[i];
        }
        sum += aji[i];
    }
    cout << sum - aji1 << endl;
}