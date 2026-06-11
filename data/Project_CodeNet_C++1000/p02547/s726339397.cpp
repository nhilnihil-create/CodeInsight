#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int s=0,maxi=0;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
        {
            s++;
            maxi=max(s,maxi);

        }
        else
        {
            s=0;
        }
    }
    if(maxi>=3)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}
