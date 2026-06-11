#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007
#define PI 3.14159265359
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int n;
     cin>>n;
     int A[n];
     for(int i=0;i<n;++i)
     {
       cin>>A[i];
	 }
	  int ans=0,ct=0;
	  for(int i=0;i<n-1;++i)
	  {
	  	if(A[i]>=A[i+1])
	  	{
	  	  ct++;
			ans=max(ans,ct);	
		}
		else
		ct=0;
	  }
	  cout<<ans<<endl;
    return 0;
}
