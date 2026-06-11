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
	int n,m;
	cin>>n>>m;
	multiset<int> cnt;
	REP(i,1,n) {
		int val;
		cin>>val;
		cnt.insert(val);
	}
	while(m--) {
		int req = *--cnt.end();
		cnt.erase(--cnt.end());
		req>>=1;
		cnt.insert(req);
	}
	ll sum = 0;
	for(int i:cnt)sum+=i;
	cout<<sum;
}//1 0 2 3 1
//1 1 3 6 7

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
