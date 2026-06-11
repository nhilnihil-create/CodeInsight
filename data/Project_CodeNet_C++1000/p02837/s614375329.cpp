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

void solve(int test_case) {//233
	int n;
	cin>>n;
	int ans = 0;
	vector<vpii> arr(n, vpii());
	REP(m,0,n-1) {
		int num;
		cin>>num;
		while(num--) {
			int x,y;
			cin>>x>>y;
			arr[m].PUB({x-1,y});
		}
	}
	for(int i=0;i<(1<<n);i++) {
		bitset<16> b(i);
		bool flag = true;
		for(int j=0;j<16;j++) {
			if(b[j]) {
				for(auto p:arr[j]) {
					if((p.S==0&&b[p.F])||(p.S==1&&!b[p.F]))flag = false;
				}
			}
		}
		if(flag)ans=max(ans,(int)b.count());
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
