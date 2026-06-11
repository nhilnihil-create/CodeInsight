#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin>>x;

    int ans=0;
    for(int k=1;k<=360;k++)
    {
        if((k*x)%360==0)
        {
            ans=k;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
