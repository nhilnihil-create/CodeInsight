#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxN = 1e5 + 10;

int n;
int a[maxN], cnt[maxN], basis[maxN];

void add(int mask){
    for(int i = 60; i >= 0; --i){
        if(mask >> i & 1){
            if(!basis[i]){
                basis[i] = mask;
                return;
            }
            else
                mask ^= basis[i];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int res = 0;
    for(int i = 60; i >= 0; --i){
        int cnt = 0;
        for(int j = 1; j <= n; ++j)
            if(a[j] >> i & 1) ++cnt;
        if(cnt & 1){
            for(int j = 1; j <= n; ++j)
                if(a[j] >> i & 1)
                    a[j] -= (1LL << i);
            res += 1LL << i;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        add(a[i]);

    for(int i = 60; i >= 0; --i){
        if(!basis[i]) continue;
        if(ans >> i & 1) continue;
        ans ^= basis[i];
    }

    cout << ans * 2 + res << endl;
}
