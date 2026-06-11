#include <bits/stdc++.h>
#define N 1000099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
LL n;
int main()
{
    cin >> n;
    LL s = sqrt(n);
    for (int i = s; i >= 1; i--)
        if (n % i == 0)
        {
            cout << i + n / i - 2 << endl;
            break;
        }
    return 0;
}
