#include <iostream>
using namespace std;

const int nmax = 250000;

int main()
{
	int pr[nmax];
	pr[0]=pr[1]=0;
	for(int i=2; i<nmax; i++)
	{
		pr[i]=1;
	}

	for(int i=2; i*i<nmax; i++)
	{
		if(!pr[i]) continue;
		for(int j=i*2; j<nmax; j+=i)
		{
			pr[j]=0;
		}
	}

	for(int i=1; i<nmax; i++)
	{
		pr[i]+=pr[i-1];
	}

	int N;
	while(cin >> N, N)
	{
		cout << pr[N*2]-pr[N] << endl;;
	}
}