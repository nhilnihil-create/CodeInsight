#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,sum=0,countt=0;
    cin>>n>>x;
    int l[n];
   //arr[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+l[i];
        if(sum<=x)
        {
            countt++;
        }
    }
    cout<<countt+1<<endl;


    return 0;
}
