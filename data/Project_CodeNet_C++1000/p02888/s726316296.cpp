#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    vector<int>a(x);
    for (int i=0; i<x; i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    for (int i=0; i<x; i++)
    {
        for (int j=i+1; j<x; j++)
        {
            int m=a[i]+a[j];
            int idx=lower_bound(a.begin(),a.end(),m)-a.begin();
            ans+=idx-j-1;
        }
    }
    cout<<ans;
    return 0;
}
