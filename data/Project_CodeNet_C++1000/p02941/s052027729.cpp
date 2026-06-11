#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],ans;
priority_queue<pair<int,int> >q;
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);q.push(make_pair(b[i],i));	
	}
	while(q.size()){
		pair<int,int> x=q.top();q.pop();
		if(a[x.second]==x.first)continue;
		if(a[x.second]>x.first){
			return puts("-1")*0;
		}
		int dis=x.first-a[x.second];
		int sum=b[x.second-1]+b[x.second+1];
		if(x.second==1)sum+=b[n];
		if(x.second==n)sum+=b[1];
		if(sum>dis){
			return puts("-1")*0;
		}
		int Dis=dis/sum;ans+=Dis;
		b[x.second]-=Dis*sum;
		q.push(make_pair(b[x.second],x.second));
	}
	cout<<ans<<endl;
	return 0;
}
