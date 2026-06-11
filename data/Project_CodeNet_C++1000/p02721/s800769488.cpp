#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    int dpl[n + 1], dpr[n + 1];
    dpl[0] = 0;
    dpr[0] = 0;
    int last = -10000000;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'x') dpl[i] = dpl[i - 1];
        else if (last + c < i) {
            last = i;
            dpl[i] = dpl[i - 1] + 1;
        }
        else dpl[i] = dpl[i - 1];
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<dpl[i]<<" ";
    // }
    // cout<<endl;
    last = -10000000;
    for (int i = 1; i <= n; ++i) {
        if (s[n - i] == 'x') dpr[i] = dpr[i - 1];
        else if (last + c < i) {
            last = i;
            dpr[i] = dpr[i - 1] + 1;
        }
        else dpr[i] = dpr[i - 1];
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<dpr[i]<<" ";
    // }
    // cout<<endl;
    //for (int i = 0; i <= n; ++i) cout << dpr[i] << " ";
    for (int i = 0; i < n; ++i) {
        int left = i;
        int right = n - i - 1;
        if (s[i] == 'o' && dpl[left] + dpr[right] < k)
        {
            //  cout<<left<<" "<<right<<endl;
            //  cout<<dpl[left]<<" "<<dpr[right]<<endl;
             cout << i + 1 << endl;
        }
    }
    return 0;
}
