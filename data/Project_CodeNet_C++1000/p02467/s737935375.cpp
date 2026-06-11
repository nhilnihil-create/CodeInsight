#include <bits/stdc++.h>
using namespace std;


vector<int> primes={2,3,5,7};
int primes_extend(int calc_from, int calc_to);
int factoring(int n, map<int,int> &factors);


int main()
{
	int n;
	cin >> n;

	primes_extend(10,100);
	primes_extend(100,10000);
	primes_extend(10000,32767);

	map<int,int> factors;
	factoring(n,factors);

	cout << n << ":";
	for (pair<int,int> p:factors)
	{
	 	// fprintf(stderr,"%d: %d\n",p.first,p.second);
		for (int j=0;j<p.second;++j)
		{
			cout << " " << p.first;
		}
	}
	cout << endl;



}

int primes_extend(int calc_from, int calc_to)
{

	for (int i=calc_from;i<=calc_to;++i)
	{
		int j;
		int loop_max=sqrt(i);
		for (j=0;(primes[j]<=loop_max)&&(j<primes.size());++j)
		{
			if ((i%primes[j])==0)
			{
				// not prime...
				break;
			}
		}
		if ((j>=primes.size())||(primes[j]>loop_max))
		{
			primes.push_back(i);
		}
	}
	//fprintf(stderr,"count: %d\n",primes.size());
}

int factoring(int n, map<int,int> &factors)
{
	int maxfactor=sqrt(n);
	for (int i=0;(n>1)&&(primes[i]<=maxfactor);++i)
	{
		while ((n%primes[i])==0)
		{
			n/=primes[i];
			factors[primes[i]]++;
		}
	}
	if (n!=1)
	{
		factors[n]++;
	}

	return 0;
}




