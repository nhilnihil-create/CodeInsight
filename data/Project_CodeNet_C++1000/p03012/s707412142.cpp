#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int W[N];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
        sum += W[i];
    }
    int ans = INT_MAX;
    int suml = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum -= W[i];
        suml += W[i];
        ans = min(ans, abs(sum - suml));
    }
    cout << ans << endl;
}