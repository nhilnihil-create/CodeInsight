#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N;
int A[300010];
int mod = 1000000007;

signed main()
{
    cin >> N;
    rep(i, N)cin >> A[i];

    int ans = 0;
    rep(i, 60)
    {
        int cnt1 = 0, cnt2 = 0;
        rep(j, N)
        {
            if(A[j] & (1ll << i))cnt1++;
            else cnt2++;
        }
        ans = (ans + (1ll << i) % mod * (cnt1 * cnt2 % mod) % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}
