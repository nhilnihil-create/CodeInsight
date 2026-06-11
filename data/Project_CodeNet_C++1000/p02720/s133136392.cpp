#include<bits/stdc++.h>
using namespace std;
queue<unsigned long long>q;
unsigned long long k;
void BFS() {
	while ( ! q.empty() ) {
		int u=q.front()%10;
		if (u-1>=0) {
			k--;
			q.push(q.front()*10+u-1);
		}
		if (k==0) {
			cout<<q.back();
			return;
		}
		k--;
		q.push(q.front()*10+u);
		if (k==0) {
			cout<<q.back();
			return;
		}
		if (u+1<=9) {
			k--;
			q.push(q.front()*10+u+1);
		}
		if (k==0) {
			cout<<q.back();
			return;
		}
		q.pop();
	}
}
int main() {
	cin>>k;
	if (k<=9) {
		cout<<k;
		return 0;
	}
	k=k-9;
	for (int i=1; i<=9; i++) {
		q.push(i);
	}
	BFS();
}