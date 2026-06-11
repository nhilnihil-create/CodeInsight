#include <iostream> 
using namespace std;
int main()
{
	int b,n; cin>>b>>n;
	int a[n],sum=0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
	}
	
	sum>b?cout<<-1:cout<<b-sum;
}
