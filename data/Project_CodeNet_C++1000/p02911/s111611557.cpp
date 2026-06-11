#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,q,i,j;
    cin>>n>>k>>q;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=k-q;
    }
    long long int b[q];
    for(i=0;i<q;i++)
    {
        cin>>b[i];
        a[b[i]-1]+=1;
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<=0)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }

}
