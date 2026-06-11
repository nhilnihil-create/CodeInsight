#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second


using namespace std;


vector<int> v;

int main()
{
	unsigned long long n;
	cin>>n;


	if(n%2!=0)
	{
		cout<<0<<endl;
		return 0;
	}

	n = n/2;

	long long pot = 5;

	long long result = 0;

	while(pot <= n)
	{
		result += n/pot;
		pot *=5;
	}

	cout<<result<<endl;


	return 0;
}
