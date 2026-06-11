#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct edge{__int128 from, to, cost;};

int main(void) {
	while(true) {
		string s;
		getline(cin, s);
		if(s.size() == 1 && s[0] == '.')break;
		bool d = true;
		stack<ll> r;
		stack<ll> b;
		REP(i, s.size()) {
			if(s[i] == '(') r.push(b.size());
			if(s[i] == ')') {
				if(r.size() == 0) {
					d = false;
					break;
				}
				ll hoge = r.top();
				r.pop();
				if(hoge != b.size()) {
					d = false;
					break;
				}
			}
			if(s[i] == '[') b.push(r.size());
			if(s[i] == ']') {
				if(b.size() == 0) {
					d = false;
					break;
				}
				ll hoge = b.top();
				b.pop();
				if(hoge != r.size()) {
					d = false;
					break;
				}
			}
		}
		if(d && b.size() == 0 && r.size() == 0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}