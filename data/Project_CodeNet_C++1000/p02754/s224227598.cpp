#include<bits/stdc++.h>
using namespace std;

#define    ll   long long 
 
int main()
{
   ll  n,a,b;
   cin>>n>>a>>b;
   
   ll full_times=n/(a+b);
   ll ans=full_times*a;
   ans=ans+min(a,n%(a+b));
   cout<< ans<<endl;
	
 
}