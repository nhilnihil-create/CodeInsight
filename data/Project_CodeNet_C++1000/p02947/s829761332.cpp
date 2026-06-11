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
ll f(ll i) {
	return i*(i-1)/2;
}
void solve(int test_case) {
	int n;
	cin>>n;
	ll cnt = 0;
	unordered_map<string,int> se;
	for(int i=0;i<n;i++) {
		string val;
		cin>>val;
		sort(val.begin(),val.end());
		se[val]++;
	}
	for(auto i:se)if(i.S>1)cnt+=f(i.S);
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
