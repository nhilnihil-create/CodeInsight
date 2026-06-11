#include <iostream>
using namespace std;
int main()
{
	string n ;
	
	while(cin>>n)
	{
		int s = n.size() ,ok=1;
		for(int i=0 ;i<s ;i++)
		{
			if(i&1) 
				if(n[i]=='R'){cout<<"No\n"; ok=0; break;}
			if(i%2==0) 
				if(n[i]=='L'){cout<<"No\n"; ok=0; break;}
		}
		if(ok) cout<<"Yes\n";
	}
} 