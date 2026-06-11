#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,s=0,ans=-1,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a;
        s+=a;
    }
    cout<<(s>n?ans:n-s)<<endl;
}
