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
	ll n,k;
	cin>>n>>k;
	ll m= (k*(k-1)/2)%MOD;
	ll ans = 0;
	vi arr(n);
	for(int &i:arr)cin>>i;
	int a = 0,b=0;
	for(int i=0;i<n;i++) {
		a=0;b=0;
		for(int j=0;j<i;j++)if(arr[j]>arr[i])a++;
		for(int j=i;j<n;j++)if(arr[j]>arr[i])b++;
		ans = (ans+(m*(a+b))%MOD)%MOD;
		ans = (ans+(a*k)%MOD)%MOD;
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
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
