#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
LL s[200020];
vector<int> v[200020];
int main(){
	LL n,k;cin>>n>>k;
	map<LL,LL> po;
	s[0]=0;
	po[0]++;
	for(LL i=1;i<=n;i++)
	{
		LL x;cin>>x;
		x--;
		if(i==1)s[1]=x;
		else s[i]=s[i-1]+x;
		s[i]=s[i]%k;
		po[s[i]]++;
		//cout<<s[i]<<"\n";
	} 
	LL ans=0;
	if(k>=n+10)
	{
		map<LL,LL>::iterator p; 
		for(p=po.begin();p!=po.end();p++)
		{
			LL y=(p->second);
			ans+=y*(y-1)/2;
		}
		cout<<ans<<"\n";
		return 0;
	}
	
	for(int i=0;i<=n;i++)
	{
		v[s[i]].push_back(i);	
	}
	for(int i=0;i<=n;i++)
	{
		int len=v[i].size();
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++)
		{
			ans+=(LL)(lower_bound(v[i].begin(),v[i].end(),v[i][j]+k)-v[i].begin())-1-j;	
		}
	}
	cout<<ans<<"\n";
	return 0;
}