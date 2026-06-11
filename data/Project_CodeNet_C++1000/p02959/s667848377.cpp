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

void solve(int test_case) {//236
	int n;
	cin>>n;
	vi a(n+1),b(n);
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	ll sum = 0;
	REP(i,0,n-1) {
		int mi = min(a[i],b[i]);
		a[i]-=mi;
		b[i]-=mi;
		sum+=mi;
		mi = min(a[i+1],b[i]);
		a[i+1]-=mi;
		b[i]-=mi;
		sum+=mi;
	}
	cout<<sum;
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
