#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define maxn 51
#define m_p make_pair 
int main(){
	int n;
	cin>>n;
	int x[maxn],y[maxn];
	for (int i=0;i<n;i++) cin>>x[i]>>y[i];
	map<pii,int> mp;
	map<pii,int>::iterator it;
	
	for (int i=0;i<n;i++)
		for (int j=0;j<i;j++){
			int dx=x[i]-x[j];
			int dy=y[i]-y[j];
			mp[m_p(dx,dy)]++;
			mp[m_p(-dx,-dy)]++;
		}
	int mx=0;
	for (it=mp.begin();it!=mp.end();it++)
		mx=max(mx,it->second);
	printf("%d\n",n-mx);
	return 0;
}