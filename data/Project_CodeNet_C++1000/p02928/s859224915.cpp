#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int>P;
const ll MOD=1e9+7;

int main()
{
	ll N,K;
	cin>>N>>K;
	vector<ll>nn;
	ll res=0;
	for(ll i=0;i<N;i++)
	{
		int t;
		cin>>t;
		nn.push_back(t);
	}
	//1
	ll t=0;
	for(ll i=1;i<N;i++)
		for(int j=0;j<i;j++)
		{
			if(nn[j]>nn[i])
			{
				t++;
			}
		}
	//2~
	ll tt=0;
	for(ll i=0;i<N;i++)
		for(ll j=0;j<N;j++)
		{
			if(nn[i]>nn[j])
			{
				tt++;
			}
		}
	//res=t;
	//for(ll p=K-1;p>0;p--)
	//	res=(res+t+tt*p)%MOD;
	ll a=(t*K)%MOD;
	ll b=((K))*(K-1)/2%MOD;
	ll c=(tt*b)%MOD;
	res=(a+c)%MOD;
	cout<<res<<endl;
}