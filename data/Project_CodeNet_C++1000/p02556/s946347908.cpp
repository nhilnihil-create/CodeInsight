#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i = 0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i] = x+y;
        b[i] = x-y;
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans = max(a[n-1]-a[0],b[n-1]-b[0]);
    cout<<ans<<endl;
    return 0;
}
