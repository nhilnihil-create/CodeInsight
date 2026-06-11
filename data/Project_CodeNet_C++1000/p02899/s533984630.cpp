# include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1; i<=n; i++)
	{
		cout<<b[i]<<" ";
	}
}