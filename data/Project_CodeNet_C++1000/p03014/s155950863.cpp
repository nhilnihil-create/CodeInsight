/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

void solve(int test_case) {
	int h,w;
	cin>>h>>w;
	vector<vi> row(h,vi()), col(w,vi());
	for(auto &i:row)i.PUB(-1);
	for(auto &i:col)i.PUB(-1);
	REP(i,0,h-1) {
		string s;
		cin>>s;
		REP(j,0,w-1) {
			if(s[j]=='#') {
				row[i].PUB(j);
				col[j].PUB(i);
			}
		}
	}
	for(auto &i:row)i.PUB(w);
	for(auto &i:col)i.PUB(h);
	int cnt = 0;
	REP(i,0,h-1) {
		REP(j,0,w-1) {
			auto inRow = lower_bound(row[i].begin(),row[i].end(),j);
			if(*inRow==j)continue;
			int ri = inRow - row[i].begin();
			int ci = lower_bound(col[j].begin(),col[j].end(),i)-col[j].begin();
			int rows = row[i][ri]-row[i][ri-1]-1;
			int cols = col[j][ci]-col[j][ci-1]-1;
			cnt=max(rows+cols-1,cnt);
		}
	}
	cout<<cnt;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
