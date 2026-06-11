#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;
const int mod = 1e9 + 7;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    int n;
    cin >> n;
    int cnt1[66] = {};
    int cnt0[66] = {};
    int twos[66] = {};
    twos[0] = 1;
    for(int i = 1; i < 62; i++)
        twos[i] = (twos[i - 1] * 2) % mod;

    int ans = 0;

    FOR(i,1,n) {
        int u;
        cin >> u;

        int add = 0;

        for(int bit = 0; bit < 62; bit++) {
            if(u >> bit & 1LL)
            {
                add = (add + cnt0[bit] * twos[bit]) % mod;
            }
            else 
            {
                add = (add + cnt1[bit] * twos[bit]) % mod;
            }
        }

        ans = (ans + add) % mod;

        for(int bit = 0; bit < 62; bit++) 
            cnt1[bit] += (u >> bit & 1LL) == 1,
            cnt0[bit] += (u >> bit & 1LL) == 0;
    }

    cout << ans;
}
