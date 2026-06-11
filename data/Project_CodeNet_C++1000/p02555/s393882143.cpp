#include "bits/stdc++.h"
using namespace std;

#define int long long
const int mod = 1e9 + 7;
int ans[100000];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ans[0]=1;
    for (int i = 0; i <= 2000; i++) {
        if(ans[i]==0)continue;
        for (int j = 3; j <= 2000; j++) {
            ans[i+j]+=ans[i];
            ans[i+j]%=mod;
        }
    }
    cout<<ans[n]<<endl;
}

