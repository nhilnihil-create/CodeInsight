#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	priority_queue<int,vector<int>,less<int> >pq;
	while(n--){
		int a;
		cin>>a;
		pq.push(a);
	}
	while(m--){
		int curr = pq.top();
		pq.pop();
		curr/=2;
		pq.push(curr);
	}
	long long ret = 0;
	while(pq.size()){
		ret+=pq.top();
		pq.pop();
	}
	cout<<ret;
}