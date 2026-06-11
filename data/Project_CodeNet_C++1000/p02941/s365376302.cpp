#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,a[N],b[N];
ll ans;
priority_queue<pair<int,int>>q;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)q.push(make_pair(b[i],i));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		int l=x==1?n:x-1,r=x==n?1:x+1;
		int w=b[x]-a[x];
		if(w==0)continue;
		if(w<(b[l]+b[r])){
			puts("-1");
			return 0;
		}
		b[x]-=w/(b[l]+b[r])*(b[l]+b[r]);
		ans+=w/(b[l]+b[r]);
		q.push(make_pair(b[x],x));
	}
	cout<<ans<<endl;
} 