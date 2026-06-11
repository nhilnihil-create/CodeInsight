# include <iostream>
# include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double k,a,b;
	if(n%2==0)
	{
		a=1;
		b=2;
		k=a/b;
		cout<<fixed<<setprecision(6)<<k;
	}
	else
	{
		a=n/2+1;
		b=n;
		k=a/b;
		cout<<fixed<<setprecision(6)<<k;
	}
}