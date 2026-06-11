#include<bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
     int n;
     cin>>n;

     int sum=0;
     for(int i=1;i<=n;i++){
       sum+=floor((n-1)/i);
     }
     cout<<sum<<endl;



}
