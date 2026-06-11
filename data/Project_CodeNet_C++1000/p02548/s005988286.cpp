#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;

    for (int A = 1; A <= N; A++)
    {
        ans += (N-1)/A ;
    }

    cout << ans << endl;
}
