#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int k;
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		cin>>k;
		pq.push(k);
	}
	for(int i=0;i<m;i++){
		if(pq.empty()) break;
		k = pq.top();
		pq.pop();
		k/=2;
		if(k!=0) pq.push(k);
	}
	long long int ans=0;
	while(!pq.empty()){
		ans+=pq.top();
		pq.pop();
	}
	cout<<ans<<endl;
}