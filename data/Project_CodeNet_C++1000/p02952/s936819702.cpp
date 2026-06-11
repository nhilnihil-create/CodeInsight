#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
       if(i<10)
            ans++;
       if(i<=999&&i>=100)
        ans++;
       if(i<=99999&&i>=10000)
        ans++;
    }
     cout<<ans<<endl;

    return 0;
}




