#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	int count=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(i%2==1 && arr[i]%2==1)
			count++;
	}
	cout<<count<<endl;
	return 0;
}