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
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> P;
const int INF=1000000000;
const int MOD_2=998244353;

P ene[200010];
int main()
{
	LL n,d,a;
	LL ans=0;
	LL count=0;
	queue<P> hoge;
	cin>>n>>d>>a;
	d*=2;
	for(int i=0;i<n;i++)cin>>ene[i].first>>ene[i].second;
	sort(ene,ene+n);
	
	for(int i=0;i<n;i++)
	{
		LL x=ene[i].first,h=ene[i].second;
		
		while(hoge.size())
		{
			if(hoge.front().first>=x)break;
			else{
				count-=hoge.front().second;
				hoge.pop();
			}
		}
		h-=a*count;
	        if(h>0)
		{
			LL kougeki=0;
			if(h%a==0)kougeki=h/a;
			else kougeki=h/a+1;	
			ans+=kougeki;
			hoge.push(P(x+d,kougeki));
			count+=kougeki;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
	