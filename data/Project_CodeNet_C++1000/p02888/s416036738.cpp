#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    vector<int>v(n);
    int i,j;
    int ans=0;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    for(i=n-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            int x=lower_bound(v.begin(),v.end(),v[i]+v[j])-v.begin();
            int y=n-x;
            ans+=n-1-i-y;
        }
    }
    cout<<ans<<endl;

}