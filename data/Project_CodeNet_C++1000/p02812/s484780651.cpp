#include <iostream>
using namespace std;

int main() {
	int i,n,count=0;
	cin>>n;
	char a[n];
	cin>>a;
	for(int i=0;i<n-2;i++)
	{
		if(a[i]=='A' && a[i+1]=='B' && a[i+2]=='C')
		{
			
			count++;
		}
	}
	cout<<count;
	return 0;
}