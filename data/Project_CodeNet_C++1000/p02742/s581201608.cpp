#include<bits/stdc++.h>
using namespace std;
signed main(void)
{
	 long long int r,c;
	 cin>>r>>c;
     
     if(r == 1 || c == 1)
     	cout<<1<<endl;
     else{
	 long long int ans = (r*c+1)/2;	
	 
	 cout<<ans<<endl;
	}
}