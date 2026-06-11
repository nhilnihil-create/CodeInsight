#include<iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
	int n;
	cin >> n;
	queue<int> q[n];
	int a;
	rep(i, n)rep(j, n-1){
		cin >> a;
		a = a - 1;
		q[i].push(a);
	}
	bool flag = true;
	int ans = 0;
	int b[n];
	rep(i, n) b[i] = 0;
	while(flag){
		flag = false;
		rep(i, n){
			if(q[i].size() != 0){
				int nxt = q[i].front();
				if(q[nxt].front() == i){
					q[i].pop();
					q[nxt].pop();
					int date = max(b[i], b[nxt]) + 1;
					b[i] = date;
					b[nxt] = date;
					flag = true;
				}
			}
		}
	}
	
	flag = true;
	rep(i, n) {
		ans = max(ans, b[i]);
		if(q[i].size() != 0){
			flag = false;
		}
	}
	if(flag){
		cout << ans << endl;
	}else{
		cout << -1 << endl;
	}
}