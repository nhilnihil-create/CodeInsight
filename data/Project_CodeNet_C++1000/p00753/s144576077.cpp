#include <iostream>

using namespace std;

bool PrimeOrNot(int p)
{
	if (p==1) return false;
	if (p==2) return true;

	for (int i=2;i*i<=p;++i)
	{
		if (p%i == 0) return false;
	}
	return true;
}

int main()
{
	int n;
	int count=0;
	cin>>n;

	while (n!=0)
	{
		for (int i=n+1;i<=2*n;++i)
		{
			if (PrimeOrNot(i)) ++count;
		}
		cout<<count<<endl;
		count =0;
		cin>>n;
	}
}