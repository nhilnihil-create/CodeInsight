#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l;
    vector<pair<int,int>>v;
    int z;
    for(int i=1;i<=n;i++)
    {
       z=l+i-1;
       v.push_back(make_pair(i,z));
    }
    int z1=0;
    for(int i=0;i<n;i++)
    {
         z1=z1+v[i].second;
    }
   int result=1000000;
   int ans=0;
    for(int i=0;i<n;i++)
    {
         int r1=z1-v[i].second;
         int r2=z1-r1;
         if(result>abs(r2))
         {
              result=abs(r2);
              ans=r2;
         }

    }
    cout<<z1-ans<<endl;
}

