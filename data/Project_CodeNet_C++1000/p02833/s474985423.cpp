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
	ull val;
	cin>>val;
	if(val&1) {
		cout<<0;
		return;
	}
	ull now = 10;
	ull ans = 0;
	ull i = 1;
	ull upto = 1e18;
	for(;val/now>=1;now*=5){ans+=(val/now);}
	//ans-=val/5;
	//for(now=50;val/now>=1;now*=10)ans+=val/now;
	//i=1;
	//for(now = 50;now<=val;now*=100,i++)ans+=val/now;
	cout<<ans;
}//10 -1 100 - 

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
