#include <bits/stdc++.h>
#include<cmath>

using namespace std;
int main()
{
    int i,n,haga,sum=0,m,c=0;
    cin>>n>>m;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    haga=ceil(sum/(4.0*(double)m));
    for(i=0;i<n;i++)
    {
        if(arr[i]>=haga)
            c++;
    }
    if(c>=m)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

   return 0;
}
