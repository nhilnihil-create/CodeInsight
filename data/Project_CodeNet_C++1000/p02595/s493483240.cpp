#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D, count;
    long long temp, x, y;
    cin >> N >> D;

    count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        temp = x * x + y * y;
        if (D >= sqrt(temp))
        {
            count++;
        }
    }
    cout << count << endl;
    return (0);
}
