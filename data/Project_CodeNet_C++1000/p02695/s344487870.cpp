#include "bits/stdc++.h"
using namespace std;
#define ll long long int
ll opt=INT_MIN;
int q;
vector<vector<ll> > cost;
void fun(int taken,vector<int> a,int n,int m,int curr)
{
	if(taken==n)
	{
		ll mycost=0;
		for(int i=0;i<q;i++)
		{
			if(a[cost[i][1]]-a[cost[i][0]]==cost[i][2])
				mycost+=cost[i][3];

		}

		opt=max(opt,mycost);
		return;
	}

	for(int i=curr;i<=m;i++)
	{
		a.push_back(i);
		fun(taken+1,a,n,m,i);
		a.pop_back();
	}

}



int main()
{
	int n,m;
	cin>>n>>m>>q;

	cost.resize(q,vector<ll>(4));

	for(int i=0;i<q;i++)
	{
		cin>>cost[i][0]>>cost[i][1]>>cost[i][2]>>cost[i][3];
		cost[i][0]--;
		cost[i][1]--;
	}


	 vector<int> a;

	fun(0,a,n,m,1);


	 cout<<opt<<endl;

	return 0;
}