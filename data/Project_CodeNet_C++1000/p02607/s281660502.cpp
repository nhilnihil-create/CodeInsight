#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[109],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if((a[i]&1)&&(i&1))
            ans++;
    }

    cout<<ans<<endl;
    return 0;
}
