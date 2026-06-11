#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float c=0.0;
    vector<float> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
   sort(v.begin(),v.end());
   c=v[0];
   for(int i=1;i<n;i++)
   {
       c=(c+v[i])/2.0;
   }
   cout<<c<<endl;
}