#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#define mod 1000000007
#define inf 1000000000000000
#define int long long int
int prime[1000001];
void sieve()
{
	prime[1]=1;
	prime[0]=1;
	int j;
	for(j=2;j<=1000000;j++)
	{
		prime[j]=j;
	}
	for(j=2;j<=1000;j++)
	{
		if(prime[j]==j)
		{
			for(int k=2;j*k<=1000000;k++)
			{
				prime[j*k]=j;
			}
		}
	}
}
int function(multiset<int> &st,int n)
{
	map<int,int> mp;
	for(int x:st)
	{
		mp[x]++;
	}
	mp[0]=n-st.size();
	while(1)
	{
		auto it1=mp.end();
		it1--;
		auto it2=mp.begin();
		int val1=it1->first;
		int val2=it2->first;
		if(val1-val2<=2)
		{
			break;
		}
		int newval1=val1-2;
		int newval2=val2+1;
		it1->second--;
		if(it1->second==0)
		   mp.erase(it1);
		it2->second--;
		if(it2->second==0)
		   mp.erase(it2);
		mp[newval1]++;
		mp[newval2]++;
	}
	auto it=mp.begin();
	return it->first;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
	 int n,m;
	 cin>>n>>m;
	 multiset<int> st;
	 int j;
	 map<int,multiset<int>> mp;
	 for(j=0;j<n;j++)
	 {
		 int a,b;
		 cin>>a>>b;
		 if(a<=m)
		 {
			 mp[a].insert(b);
		 }
	 }
	 int answer=0;
	 for(j=1;j<=m;j++)
	 {
		 for(int x:mp[j])
		 {
			 st.insert(x);
		 }
		 if(st.size()!=0)
		 {
			 auto it=st.end();
			 it--;
			 answer+=(*it);
			 st.erase(it);
		 }
	 }
	 cout<<answer<<endl;
}
