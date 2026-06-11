#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
   int z=0;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
          z=z+(v[i]*v[j]);
       }
   }
   cout<<z<<endl;



    return 0;
}
