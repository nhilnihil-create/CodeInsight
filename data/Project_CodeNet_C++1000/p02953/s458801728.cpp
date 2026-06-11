#include <iostream>
#include <algorithm>
using namespace std;
int n ,o[100005] ,s[100005];
int main() 
{	
	while(cin>>n)
	{
		int ok=1;
		for(int i=0 ;i<n ;i++) cin>>o[i] ,s[i]=o[i];
		if(is_sorted(o ,o+n)){cout<<"Yes\n"; continue;}
		sort(s ,s+n);
		for(int i=0 ;i<n ;i++)		
			if(abs(o[i]-s[i])>1){ok=0; break;}
		if(ok) cout<<"Yes\n";
		else cout<<"No\n";
	}	
}