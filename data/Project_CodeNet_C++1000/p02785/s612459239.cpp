#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,k;
    cin>>n>>k;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
  	long long int sum=0;
    if(n-k<=0)
    {
        cout<<"0";return 0;
    }
    else
    {
        for(i=0;i<n-k;i++)
        {
           sum+=a[i];
        }
    }
    cout<<sum;
}
