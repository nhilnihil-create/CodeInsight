#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>k>>n;
   if(k==1)
    cout<<n<<endl;
   else
   {
       vector<int>v;
       int z=n;
       v.push_back(n);
       for(int i=1;i<k;i++)
       {
          z--;
          v.push_back(z);
       }
       int z1=n;
       for(int i=1;i<k;i++)
       {
          z1++;
          v.push_back(z1);
       }
       sort(v.begin(),v.end());
       for(auto c:v)
        cout<<c<<" ";
   }

    return 0;
}


