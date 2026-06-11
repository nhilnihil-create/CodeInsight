#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N],b[N];
int main(){
	priority_queue<pair<int,int>> pq;
	int n;
	long long cnt=0;
	bool gg=false;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		pq.push(make_pair(b[i],i));
	}
	while(!pq.empty()){
		auto p=pq.top();
		pq.pop();
		int i=p.second;
		if(p.first!=b[i]) continue;
		int nb=b[(i+1)%n]+b[(i+n-1)%n];
		if(b[i]>=nb){
			if(b[i]%nb<=a[i]){
				if(b[i]%nb!=a[i]%nb){
					gg=true;
					break;
				}
				else{
					cnt+=(b[i]-a[i])/nb;
					b[i]=a[i];
				}
			}
			else{
				cnt+=b[i]/nb;
				b[i]%=nb;
				pq.push(make_pair(b[i],i));
			}
		}
	}
	for(int i=0;i<n;i++) if(a[i]!=b[i]) gg=true;
	if(gg) puts("-1");
	else printf("%lld\n",cnt);
	return 0;
}