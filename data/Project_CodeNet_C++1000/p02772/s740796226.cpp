#include<iostream>
using namespace std;
int main(){
	int n;
	int x;
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x%2==0)
		{
			if(x%3==0||x%5==0)
				continue;
			else 
			{
				cout<<"DENIED"<<endl;
				return 0;
			}
				
		}
		else 
			continue;
	}
	cout<<"APPROVED"<<endl;
	return 0;
}