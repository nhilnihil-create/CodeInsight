#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,q,ans=0;
    cin>>n>>k>>q;
    int a[n]={};
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        a[x-1]++;
    }
    for(int i=0;i<n;i++)
      {
         if((a[i]+k-q)>0)
         cout<<"Yes\n";
         else
            cout<<"No\n";
      }
    return 0;
}

