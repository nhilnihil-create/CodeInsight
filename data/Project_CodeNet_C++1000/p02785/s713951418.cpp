#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int h[n];

    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }

    sort(h,h+n);
    long long int sum=0;

    if(n>k)
    {
         for(int i=0;i<n-k;i++)
         {
             sum+=h[i];
         }
         cout<<sum<<endl;
    }

    else
    {
        cout<<0<<endl;
    }

    exit(0);

}
