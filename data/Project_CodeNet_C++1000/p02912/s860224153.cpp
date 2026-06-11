#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	priority_queue<int,vector<int>,less<int> >pq;
	
	while(n--){
		int price;
		cin>>price;
		pq.push(price);
	}
	while(m-- && pq.size()){
		int curr = pq.top();
		pq.pop();
		curr/=2;
		if(curr) pq.push(curr);
	}
	long long ret = 0;
	while(pq.size()){
		ret+=pq.top();
		pq.pop();
	}
	cout<<ret;
}