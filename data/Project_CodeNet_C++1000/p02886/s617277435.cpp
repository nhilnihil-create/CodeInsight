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
        int n;;
        cin>>n;
        int a[n];
        int count=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count+=a[i]*a[j];
            }
        }
        cout<<count<<endl;
    }
    return 0;
}