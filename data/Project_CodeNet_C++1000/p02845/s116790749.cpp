#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N;
int A[1000010];
int mem[1000010];
int mod = 1000000007;

signed main()
{
    cin >> N;

    mem[0] = 3;
    int ans = 1;
    rep(i, N)
    {
        int a;
        cin >> a;
        ans = ans * mem[a] % mod;
        mem[a]--;
        mem[a + 1]++;
    }

    cout << ans << endl;

    return 0;
}
