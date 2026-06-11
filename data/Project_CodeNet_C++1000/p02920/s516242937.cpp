#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;

LL n,a[1000005] = {0};
LL tot[1000005] = {0},tcn = 0;
priority_queue <LL> q,p;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1;i <= (1LL << n);i ++) cin >> a[i];
	sort(a + 1,a + 1 + (1LL << n));
	LL tmp = 1;
	for(LL i = (1LL << n) - 1;i >= 0;i --){
		if(a[i] == a[i + 1]) tmp ++;
		else{
			tot[++ tcn] = tmp;
			tmp = 1;
		}
	}
	
	q.push(n + 1);
	for(LL i = 1;i <= tcn;i ++){
		if(q.size() < tot[i]){
			cout << "No" << endl;
			return 0;
		}
		for(LL j = 1;j <= tot[i];j ++){
			tmp = q.top(); q.pop();
			for(LL k = 1;k < tmp;k ++) p.push(k);
		}
		while(!p.empty()){
			q.push(p.top());
			p.pop();
		}
	}
	cout << "Yes" << endl;
	return 0;
}