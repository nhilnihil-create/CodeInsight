#include <bits/stdc++.h>
#define D(x) cout << #x << "=" << x << endl
#define De(...)
using namespace std; 

int _; 
 
int n,a[200020],b[200020];
vector<pair<int,int> > v;
long long cnt=0; 
 
int main()
{
	//for(scanf("%d",&_);_;_--)
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{	
		scanf("%d%d",a+i,b+i);
		v.push_back(pair<int,int> (b[i],a[i]));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		cnt += v[i].second;
		if(cnt>v[i].first)
			return puts("No"),0;	
	} 
	return puts("Yes"),0;
}
