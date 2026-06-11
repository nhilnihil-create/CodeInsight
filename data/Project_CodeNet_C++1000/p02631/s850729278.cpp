#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll  a[500000];
ll sum=0;
int main()
{
    int n;
    cin>>n;
    cin>>sum;
    a[0]=sum;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        sum=sum^a[i];
    }
    for(int i=0;i<n;i++)
    {
        int k=sum^a[i];
        cout<<k<<" ";
    }
   
}