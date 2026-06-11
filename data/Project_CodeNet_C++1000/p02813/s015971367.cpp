#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v;
    int n,ar[200],ar1[200],first=-1,second=-1,ar3[207];
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>ar[i];
    for(int i=1; i<=n; i++)
        cin>>ar1[i];
    for(int i=1; i<=n; i++)
        ar3[i]=i;
    int cnt=1,flag=0;
    for(int i=1; i<=n; i++)
        if(ar[i]!=ar1[i])
            flag=1;
    if(flag==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int flag1=0,flag2=0;
    for(int i=1; i<=n; i++)
    {
        if(ar[i]!=ar3[i])
            flag1=1;
        if(ar1[i]!=ar3[i])
            flag2=1;
    }
    if(flag1==0)
        first=1;
    if(flag2==0)
        second=1;
    while(next_permutation(ar3+1,ar3+n+1))
    {
        cnt++;
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(ar3[i]!=ar[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            first=cnt;
        flag=0;
        for(int i=1; i<=n; i++)
        {
            if(ar3[i]!=ar1[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            second=cnt;
        if(first!=-1&&second!=-1)
        {
            cout<<abs(first-second)<<endl;
            return 0;
        }
    }
    // cout<<abs(first-second)<<endl;
    return 0;
}
