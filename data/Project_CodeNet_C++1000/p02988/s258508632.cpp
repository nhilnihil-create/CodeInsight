#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];

    int ans = 0;
    for (int i = 0; i < N - 2; i++)
        if ((list[i] < list[i + 1] && list[i + 1] < list[i + 2]) || (list[i] > list[i + 1] && list[i + 1] > list[i + 2]))
            ans++;
    cout << ans;
}