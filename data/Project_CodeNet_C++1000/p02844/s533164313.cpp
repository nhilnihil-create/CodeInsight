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
	int n,ans=0;
	cin>>n;
	string s;
	cin>>s;
	bitset<10> a;
	REP(i,0,n-3) {
		if(a[s[i]-'0'])continue;
		a[s[i]-'0']=1;
		bitset<10> b;
		REP(j,i+1,n-2) {
			if(b[s[j]-'0'])continue;
			b[s[j]-'0']=1;
			bitset<10> c;
			REP(k,j+1,n-1)c[s[k]-'0']=1;
			ans+=c.count();
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
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
