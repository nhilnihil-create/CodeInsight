#include <iostream>
#include <algorithm>
using namespace std;
long long a ,b ,c ,d;
int main() 
{	
	while(cin>>a>>b>>c>>d)
	{
		cout<<max(a*c ,max(a*d ,max(b*d ,b*c)))<<'\n';
	}	
	
}