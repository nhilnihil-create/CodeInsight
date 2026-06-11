#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
        	long long n;
	       cin>>n;
	       long long ans=0;
	       for(long long i=1;i<=n;i++)
           {
	           long long no=n/i;
	           long long lst=no*i;
	           long long res=no*(i+lst);
	           res/=2;
               ans+=res;
	       }
      cout<<ans;

 
  
  return 0;
}
