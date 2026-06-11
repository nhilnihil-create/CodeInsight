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

void solve(int test_case) {
	int n,m;
	cin>>n>>m;
	vi arr(n,0);
	while(m-->0) {
		int a,b;
		cin>>a>>b;
		if((a==1&&b==0&&n!=1)||(arr[a-1]!=0&&arr[a-1]!=b)||a>n) {
			cout<<-1;
			return;
		}
		arr[a-1]=b;
	}
	if(arr[0]==0&&n>1)arr[0]=1;
	for(int i=0;i<n;i++)cout<<arr[i];
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
