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

void solve(int test_case) {//209
	int n,m,x;
	cin>>n>>m>>x;
	vi c(n);
	vector<vi> a(n,vi(m));
	int ans = -1;
	REP(i,0,n-1) {
		cin>>c[i];
		for(int &j:a[i]) cin>>j;
	}
	for(int i=0;i<(1<<n);i++) {
		vi now(m,0);
		int cnt=0;
		for(int j=0;j<n;j++) {
			if(1&(i>>j)) {
				REP(k,0,m-1)now[k]+=a[j][k];
				cnt+=c[j];
			}
		}
		bool isSol = true;
		for(int j:now){if(j<x){isSol=0;break;}}
		if(isSol) {
			if(ans==-1)ans=cnt;
			else ans=min(ans,cnt);
		}
	}
	cout<<ans;
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
	//prefill();
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
