#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,ans=2;
    cin>>n>>x;
    int l[n];
    int m[n];

    for(int i=0; i<n; i++)
    {
        cin>>l[i];
    }
    m[0]=l[0];

    for(int i=1; i<n; i++)
    {
        m[i]=m[i-1]+l[i];

        if(m[i]<=x)
            ans++;
    }
    cout<<ans<<endl;
}
