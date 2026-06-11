#include <iostream>
using namespace std;
int main()
{
	string n ;
	
	while(cin>>n)
	{
		if(n=="Sunny")cout<<"Cloudy\n";
		else if(n=="Cloudy") cout<<"Rainy\n";
		else cout<<"Sunny\n";
	}
} 