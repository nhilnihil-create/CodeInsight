#include<bits/stdc++.h>
using namespace std;
#define first ff
#define second ss
#define ll long long int
int main()
{
   int n;
   cin>>n;
   int a[n+5],b[n+5],c[n+5];
   ll sum=0;
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>b[i],sum+=b[i];
   for(int i=0;i<n-1;i++) cin>>c[i];
   for(int i=0;i<n-1;i++){
      if(a[i]+1==a[i+1]) sum+=c[a[i]-1];
   }
   cout<<sum<<endl;

}
