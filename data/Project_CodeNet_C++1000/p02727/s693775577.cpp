#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,c;
int main(){
	cin>>x>>y>>a>>b>>c;
	priority_queue<int,vector<int>,greater<int> >pq_a;
	priority_queue<int,vector<int>,greater<int> >pq_b;
	priority_queue<int,vector<int>,less<int> >pq_c;
	while(a--){
		int a;
		cin>>a;
		pq_a.push(a);
	}
	while(b--){
		int a;
		cin>>a;
		pq_b.push(a);
	}
	while(c--){
		int a;
		cin>>a;
		pq_c.push(a);
	}
	while(pq_a.size()>x) pq_a.pop();
	while(pq_b.size()>y) pq_b.pop();
	while(pq_c.size()){
		int curr = pq_c.top();
		pq_c.pop();
		if(curr<=pq_a.top() && curr<=pq_b.top()) break;
		if(pq_a.top()>pq_b.top()){
			pq_b.pop();
			pq_b.push(curr);
		}
		else{
			pq_a.pop();
			pq_a.push(curr);
		}
	}
	long long ret = 0;
	while(pq_a.size()){
		ret+=pq_a.top();
		pq_a.pop();
	}
	while(pq_b.size()){
		ret+=pq_b.top();
		pq_b.pop();
	}
	cout<<ret;
}