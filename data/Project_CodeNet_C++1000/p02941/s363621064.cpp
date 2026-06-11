#include <bits/stdc++.h>
#define pa pair<int,int>
using namespace std;
priority_queue<pa> qwq;
int a[200005],b[200005],N;
int main(){
	scanf("%d",&N);
	long long ans=0;
	for (int i=1;i<=N;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		qwq.push(make_pair(a[i],i));
	}
	while (!qwq.empty()){
		pa now=qwq.top();
		qwq.pop();
		if (b[now.second]>now.first) {
			puts("-1");
			return 0;
		}
		if (b[now.second]==now.first) continue;
		int Ned=now.first-b[now.second];
		int tmp=a[now.second-1]+a[now.second+1];
		if (now.second==1) tmp+=a[N];
		if (now.second==N) tmp+=a[1];
		if (tmp>Ned){
			printf("-1\n");
			return 0;
		}
		int tmp1=Ned/tmp;
		ans+=tmp1;
		a[now.second]-=tmp1*tmp;
		now.first=a[now.second];
		qwq.push(now);
	}
	cout<<ans;
	return 0;
}