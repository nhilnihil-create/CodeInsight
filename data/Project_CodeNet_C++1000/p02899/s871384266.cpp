#include<iostream>
#include<algorithm>
using namespace std;
struct data
{
	int id,p;
}a[100100];
int coo(struct data x,struct data y)
{
	if(x.p<y.p)  return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)   cin>>a[i].p,a[i].id=i;
	sort(a+1,a+n+1,coo);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].id<<" ";
	}
	return 0;
}