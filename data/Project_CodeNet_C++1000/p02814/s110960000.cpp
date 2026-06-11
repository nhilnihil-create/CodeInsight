#include <bits/stdc++.h>
using namespace std;

int64_t get_lcm32(vector<int> &a);

int main()
{

	int n,m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i=0;i<n;++i)
	{
		cin >> a[i];
	}

	for (int i=0;i<n;++i)
	{
		a[i]/=2;
	}

	// check count of pow2
	int count_of_pow2=-1;
	for (int i=0;i<n;++i)
	{
		int count=0;
		int aa=a[i];
		while ((aa%2)==0)
		{
			aa/=2;
			++count;
		}
		if (count_of_pow2>=0)
		{
			if (count!=count_of_pow2)
			{
				// not all pow2 are same, then no semi-common-multiple exists...
				cout << 0 << endl;
				return 0;
			}
		}
		else
		{
			count_of_pow2=count;
		}
	}

	int64_t lcm=get_lcm32(a);
	if (lcm<0)
	{
		cout << 0 << endl;
		return 0;
	}

	cout << m/lcm-m/(2*lcm) << endl;
	return 0;
}

int64_t get_lcm32(vector<int> &a)
{
	int64_t lcm;

	if (a.size()<=0)
	{
		return -1;
	}
	lcm=a[0];

	for (int i=1;i<a.size();++i)
	{
		lcm=lcm/__gcd(lcm,(int64_t)a[i])*a[i];
		if (lcm>=(int64_t)1<<32)
		{
			return -1;
		}
	}
	return lcm;
}







