#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin >> t;
    while (t--) {
        int a,b;
        cin>>a>>b;
        cout<<(2*b>a?0:a-2*b)<<endl;
    }
    return 0;
}