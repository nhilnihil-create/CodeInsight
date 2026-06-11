#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,n,t,i,j,k,x,y,m,p,s,mx,mn;
    cin>>t;
    char ar[t];
    c=1;
    for(i=0;i<t;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<t-1;i++)
    {
        if(ar[i]!=ar[i+1])
        {
            c++;
        }
    }
    cout<<c<<endl;
}
