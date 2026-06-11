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
	int n,m;
	cin>>n>>m;
	vi arr(n+1,0);
	set<int> broken;
	while(m--){
		int val;
		cin>>val;
		broken.insert(val);
	}
	arr[0]=1;
	if(broken.count(1)==0)arr[1]=1;
	REP(i,2,n) {
		if(broken.count(i))arr[i]=0;
		else arr[i]+=(arr[i-1]+arr[i-2])%MOD;
	}
	cout<<arr[n];
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
