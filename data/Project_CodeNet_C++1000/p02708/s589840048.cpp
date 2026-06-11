#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N, K;
int mod = 1000000007;

signed main()
{
    cin >> N >> K;
    int l = 0, r = 0;
    int ans = 0;
    for(int i = 0; i < K - 1; i++)
    {
        l += i;
        r += N - i;
    }
    for(int i = K; i <= N + 1; i++)
    {
        l += i - 1;
        r += N - i + 1;
        ans = (r - l + 1 + ans) % mod;
    }

    cout << ans << endl;

    return 0;
}
