#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int A, B, M;
    cin >> A >> B >> M;
    int a[A], b[B];
    int mina = 200000, minb = 200000;

    for (int i = 0; i < A; i++)
    {
        cin >> a[i];
        if (a[i] < mina)
            mina = a[i];
    }
    for (int i = 0; i < B; i++)
    {
        cin >> b[i];
        if (b[i] < minb)
            minb = b[i];
    }
    int ans = mina + minb;
    int x, y, c;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> c;
        if (a[x - 1] + b[y - 1] - c < ans)
            ans = a[x - 1] + b[y - 1] - c;
    }
    cout << ans << endl;
    return 0;
}