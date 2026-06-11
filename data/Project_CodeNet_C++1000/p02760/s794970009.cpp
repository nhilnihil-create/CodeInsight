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
	vector<vi> a(3,vi(3));
	for(auto &i:a)for(auto &j:i)cin>>j;
	int n;
	cin>>n;
	while(n--) {
		int val;
		cin>>val;
		for(auto &i:a)for(auto &j:i)if(j==val)j=-1;
	}
	bool ans = false;
	ans|=a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==-1;
	ans|=a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[0][2]==-1;
	REP(i,0,2) {
		bool curr = true;
		REP(j,0,2) curr&=a[i][j]==-1;
		ans|=curr;
	}
	REP(i,0,2) {
		bool curr = true;
		REP(j,0,2) curr&=a[j][i]==-1;
		ans|=curr;
	}	
	cout<<(ans?"Yes":"No");	
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
