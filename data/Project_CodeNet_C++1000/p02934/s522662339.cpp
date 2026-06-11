#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   vector<int>v;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       v.push_back(x);
   }
   double ans=0;
   double devide=0;
   for(int i=0;i<n;i++)
   {
       devide=devide+(1/(double)v[i]);
       ans=1/devide;
   }
   cout<<ans<<endl;


    return 0;
}

