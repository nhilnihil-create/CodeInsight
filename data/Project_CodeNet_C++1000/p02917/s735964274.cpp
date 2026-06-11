#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    // 1 1 2 2 3 3 6 2  2
    // 1 9 2 8 3 7 6 2
    // 2 2 5
    // 2 5
    int n;
    cin>> n;
    vector<int> ar(n-1);
    for(int i=0;i<n-1;i++)
        cin>>ar[i];
    vector<int> ans(n);
    ans[0]=ar[0];
    ans[n-1]=ar[n-2];
    for(int i=1;i<n-1;i++)
        ans[i]=min(ar[i],ar[i-1]);
    int final_ans=0;
    for(int i=0;i<n;i++)
        final_ans+=ans[i];
    cout<<final_ans;
    return 0;
}
//17:05
//13+5+8+24