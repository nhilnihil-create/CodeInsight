#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n;
    cin >> n;
    n++;
    vector<int> a(n), b(n - 1);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int ans=0;
    for (int i = 0; i < n - 1; i++)
    {
        if(a[i]<=b[i])
        {
            ans+=a[i];
            b[i]-=a[i];
            a[i]=0;
        }
        else
        {
            ans+=b[i];
            a[i]-=b[i];
            b[i]=0;
        }
        if(a[i+1]<=b[i])
        {
            ans+=a[i+1];
            a[i+1]=0;
        }
        else
        {
            ans+=b[i];
            a[i+1]-=b[i];
        }
    }
    
    cout<<ans;
    return 0;
}