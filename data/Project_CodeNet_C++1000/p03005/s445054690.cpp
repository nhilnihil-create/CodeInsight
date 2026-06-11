#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ar[113],i,ans,Max = 0;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        ar[i] = 1;
    }
    ans = n - k;
    ar[k] = ar[k] + ans;
    if(k==1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        for(i=1; i<k; i++)
        {
            if((ar[i+1]-ar[i])>Max)
            {
                Max = ar[i+1] - ar[i];
            }
        }
        cout<<Max<<endl;
    }

    return 0;
}
