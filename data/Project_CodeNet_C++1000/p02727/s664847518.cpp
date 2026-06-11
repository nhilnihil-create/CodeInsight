#include<bits/stdc++.h>
#define N 100005
using namespace std;
priority_queue<long long>q[3];
long long a[N],b[N],c[N],ans;
int main(){
	int n,m,A,B,C;
	cin>>n>>m>>A>>B>>C; 
	for(int i=1;i<=A;i++)scanf("%lld",&a[i]),q[0].push(a[i]);
	for(int i=1;i<=B;i++)scanf("%lld",&b[i]),q[1].push(b[i]);
	for(int i=1;i<=C;i++)scanf("%lld",&c[i]),q[2].push(c[i]);
	for(int i=1;i<=n;i++){
		long long t=q[0].top();q[0].pop();
		q[2].push(t);
	}
	for(int i=1;i<=m;i++){
		long long t=q[1].top();q[1].pop();
		q[2].push(t);
	}
	for(int i=1;i<=n+m;i++){
		ans+=q[2].top();q[2].pop();
	}
	cout<<ans;
} 