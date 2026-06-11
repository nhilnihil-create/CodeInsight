#include<bits/stdc++.h>
using namespace std;

int a[200001],b[200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	priority_queue<pair<int,int> > pq;
	long long int ans=0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i])
			pq.push(make_pair(b[i],i));
	while(!pq.empty()){
		auto now=pq.top();pq.pop();
		int neighbor=b[(now.second+1)%n]+b[(now.second+n-1)%n];
		if(b[now.second]-a[now.second]<neighbor){
			cout<<-1<<endl;
			return 0;
		}
		ans+=(b[now.second]-a[now.second])/neighbor;
		b[now.second]=a[now.second]+(b[now.second]-a[now.second])%neighbor;
		if(a[now.second]!=b[now.second])
			pq.push(make_pair(b[now.second],now.second));
	}
	cout<<ans<<endl;
}
