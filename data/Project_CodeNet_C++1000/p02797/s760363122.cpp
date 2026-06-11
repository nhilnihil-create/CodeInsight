#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, k, s;

int main(void){
	cin >> n >> k >> s;
	queue<lli> q;
	while(k--) q.push(s);
	while(q.size() < n){
		if(s < 1e9) q.push(s+1);
		else q.push(1);
	}
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}
