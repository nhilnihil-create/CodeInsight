#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n,k;
    cin >> n>>k;
    vector<double> ar(n),prefix(n);
    for (auto &i : ar)
    {
        cin >> i;
        int temp = i;
        i = i * (i + 1) / 2.0;
        i = i / temp;
    }
    prefix[0]=ar[0];
    for (int i = 1; i < n ; i++)
        prefix[i]=prefix[i-1]+ar[i];
    double ans=prefix[k-1];
    for(int i=k;i<n;i++)
        ans=max(ans,prefix[i]-prefix[i-k]);
    cout<<fixed<<setprecision(14)<<ans;
    return 0;
}