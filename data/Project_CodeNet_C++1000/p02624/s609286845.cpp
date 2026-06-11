#include<bits/stdc++.h>
using namespace std;

#define int long long

int N;

signed main()
{
    cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j += i)ans += j;
    }
    cout << ans << endl;
    return 0;
}
