#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define ll long long

int n;
int arr[200005];
int brr[200005];
priority_queue<ii> pq;

void rage(){
	printf("-1\n");
	exit(0);
}

int main(){
	cin>>n;
	for (int x=0;x<n;x++) cin>>arr[x];
	for (int x=0;x<n;x++) cin>>brr[x];
	
	for (int x=0;x<n;x++){
		if (arr[x]>brr[x]) rage();
		else if (arr[x]<brr[x]) pq.push(ii(brr[x],x));
	}
	
	int pos,temp,diff;
	ll ans=0;
	while (!pq.empty()){
		//printf("%d %d\n",pq.top().first,pq.top().second);
		pos=pq.top().second,pq.pop();
		
		temp=brr[(pos+1)%n]+brr[(pos-1+n)%n];
		diff=brr[pos]-arr[pos];
		
		if (diff<temp) rage();
		ans+=diff/temp;
		brr[pos]=arr[pos]+diff%temp;
		
		if (arr[pos]<brr[pos]){
			pq.push(ii(brr[pos],pos));
		}
	}
	
	printf("%lld\n",ans);
}