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

int main(void) {
	int m;
	cin>>m;
	REP(i, m) {
		string s;
		cin>>s;
		set<string> p;
		FOR(j, 1, s.size()) {
			string f = s.substr(0, j);
			string b = s.substr(0 + j, s.size() - j);
			if(p.count(f + b) == 0) {
				p.insert(f + b);
			}
			if(p.count(b + f) == 0) {
				p.insert(b + f);
			}
			reverse(ALL(f));
			if(p.count(f + b) == 0) {
				p.insert(f + b);
			}
			if(p.count(b + f) == 0) {
				p.insert(b + f);
			}
			reverse(ALL(b));
			if(p.count(f + b) == 0) {
				p.insert(f + b);
			}
			if(p.count(b + f) == 0) {
				p.insert(b + f);
			}
			reverse(ALL(f));
			if(p.count(f + b) == 0) {
				p.insert(f + b);
			}
			if(p.count(b + f) == 0) {
				p.insert(b + f);
			}
		}
		cout<<p.size()<<endl;
	}
}