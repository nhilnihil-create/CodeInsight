#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second


using namespace std;


vector<int> v;

int main()
{
	int n;
	int t;
	cin>>n;

	for(int i = 0; i<n; i++)
	{
		cin>>t;
		v.pb(t);
	}

	bool hav1 = false;
	for(auto &i : v)
	{
		if(i==1)
			hav1 = true;			
	}

	if(!hav1)
	{
		cout<<-1<<endl;
		return 0;
	}

	int atu = 1;
	for(auto &i : v)
	{
		if(i==atu)
			atu++;
	}

	cout<<n-atu+1<<endl;


	return 0;
}
