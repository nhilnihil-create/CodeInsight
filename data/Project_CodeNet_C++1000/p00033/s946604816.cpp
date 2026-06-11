#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define rep2(x,from,to) for(int x = (from); x < (to); ++(x))
#define rep(x,to) rep2(x,0,to) 
void dfs(stack<int> s, stack<int> r, stack<int> l, bool &f) {
	if(s.empty()) {
		f = 1;
		return;
	}
	int x = s.top();
	if(r.empty() || r.top() < x) {
		s.pop();
		r.push(x);
		dfs(s,r,l,f);
		r.pop();
		s.push(x);
	}
	if(l.empty() || l.top() < x) {
		s.pop();
		l.push(x);
		dfs(s,r,l,f);
		l.pop();
		s.push(x);
	}
}
int main() {
	int n;
	cin >> n;
	while(n--) {
		int a[10];
		stack<int> s;
		rep(i,10) {
			cin >> a[i];
		}
		rep(i,10) {
			s.push(a[10-i-1]);
		}
		stack<int> r;
		stack<int> l;
		bool f = 0;
		dfs(s,r,l,f);
		if(f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}