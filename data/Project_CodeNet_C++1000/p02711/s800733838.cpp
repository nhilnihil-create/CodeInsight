#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,flag=0;
    cin>>t;
	while(t!=0)
	{
		
	int x= t%10;
	if(x==7)
	{
		flag=1;
		break;
	}
	
		t/=10;
	}
    
    if(flag==1)
    	cout<<"Yes";
    else
    	cout<<"No";
    
    
    return 0;
}