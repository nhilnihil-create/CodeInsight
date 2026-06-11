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

void solve(int test_case) {//234 Coloring Colorfully
	int n;
	cin>>n;
	vi a(n),b(n),c(n-1);
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	for(int &i:c)cin>>i;
	ll sum = 0;
	sum+=b[a[0]-1];
	REP(i,1,n-1) {
		sum+=b[a[i]-1];
		if(a[i]-a[i-1]==1) {
			sum+=c[a[i-1]-1];
		}
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
