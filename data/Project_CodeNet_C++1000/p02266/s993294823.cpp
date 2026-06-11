#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define REP(i,n) for(unsigned int i=0;i<n;++i)
#define RREP(i,n) for(unsigned int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define INF 1000000001
#define MOD 1000000007

using namespace std;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int s = 0,a=0;
	stack<int> l;
	stack<pair<int,int> > v;
	string c;
	int i = 0;
	cin >> c;
	REP(i, c.size()) {
		if (c[i] == '\\') {
			l.push(i);
		}
		else if (c[i] == '/' && !l.empty()) {
		
			s = i - l.top();
			a += s;
			while (!v.empty() && v.top().second > l.top()) {
				s += v.top().first;
				v.pop();
			}	
			v.push(MP(s, l.top()));
			s = 0;
			l.pop();
		}
	}
	int k = v.size();
	cout << a << endl;
	cout << k;
	stack<int> res;
	REP(i, k) {
		int a = v.top().first;
		v.pop();
		res.push(a);
	}
	REP(i, k) {
		cout << " " << res.top();
		res.pop();
	}
	cout << endl;
	return 0;
}