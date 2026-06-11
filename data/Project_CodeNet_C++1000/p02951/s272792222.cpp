#include <iostream>
using namespace std;
int n ,m ,k ,t;
int main() 
{	
	int a ,b ,c;
	while(cin>>a>>b>>c)
	{
		int res = b+c-a;
		if(res<=0) cout<<"0\n";
		else cout<<res<<'\n';
	}	
}