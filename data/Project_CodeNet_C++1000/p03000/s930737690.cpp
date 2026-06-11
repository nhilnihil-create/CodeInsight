#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int a,sum=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
        if(sum<=x)
        {
            cnt++;
        }
    }
    cout<<cnt+1<<endl;
}
