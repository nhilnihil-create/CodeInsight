#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int mn=1e5+8;
vector<pii > p;
multiset<int> s;

int main()
{
	int n,a;
	long long ans=0;
	scanf("%d",&n);
	s.insert(n+1);s.insert(n+1);
	s.insert(0),s.insert(0);
	for(int i=1;i<=n;++i) {scanf("%d",&a);p.push_back(make_pair(a,i));}
	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	for(int i=1;i<=n;++i) {
		pii now=p[i-1];
		int id=now.second,val=now.first;
		if(i>1) {
			int prepre=*----s.lower_bound(id);
			int pre=*--s.lower_bound(id);
			int nxt=*s.lower_bound(id);
			int nxtnxt=*++s.lower_bound(id);
			ans+=1ll*val*(1ll*(id-pre)*(nxtnxt-nxt)+1ll*(nxt-id)*(pre-prepre));
		}
		s.insert(id);
	}
	cout<<ans;
}