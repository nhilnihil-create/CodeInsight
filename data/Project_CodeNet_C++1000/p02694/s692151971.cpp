#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int x,p=100,step=0;
	cin>>x;
	while(x>p)
	{
	    p+=p/100;
	    step++;
	}
	cout<<step<<endl;
	return 0; 
} 
