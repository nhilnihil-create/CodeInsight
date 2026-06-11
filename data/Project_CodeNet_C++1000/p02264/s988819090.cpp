#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
using namespace std;

#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int n, q;
queue<pair<string, int> > qu;
int main() {
	cin >> n >>	q;
	rep(i,n) {
		string s;
		int t;
		cin >> s >> t;
		qu.push(make_pair(s, t));	
	}
	int time = 0;
	while(!qu.empty()) {
		pair<string, int> p = qu.front();
		qu.pop();
		if(p.second > q) {
			p.second -= q;
			time += q;
			qu.push(p);
		} else {
			time += p.second;
			cout << p.first << " " << time << endl;
		}
	}
	return 0;
}