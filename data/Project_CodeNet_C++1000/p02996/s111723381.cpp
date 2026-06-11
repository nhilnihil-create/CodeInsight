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

bool cmp (pair<int,int>& a, pair<int,int> &b) {
	if(a.S==b.S)return a.F<b.F;
	return a.S<b.S;
}

void solve(int test_case) {//236
	int n;
	cin>>n;
	vpii arr(n);
	for(int i=0;i<n;i++)cin>>arr[i].F>>arr[i].S;
	sort(arr.begin(),arr.end(),cmp);
	int t=0;
	for(auto i:arr) {
		t+=i.F;
		if(t>i.S) {
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
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
