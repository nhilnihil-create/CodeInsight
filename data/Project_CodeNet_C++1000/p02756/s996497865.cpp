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
	string s;
	cin>>s;
	int n;
	cin>>n;
	bool rev = false;
	while(n--) {
		int t;
		cin>>t;
		if(t==1)rev=!rev;
		else {
			int f;char c;
			cin>>f>>c;
			if(!rev) {
				if(f==1)s=c+s;
				else s+=c;
			} else {
				if(f==1)s+=c;
				else s=c+s;
			}
		}
	}
	if(rev)reverse(s.begin(),s.end());
	cout<<s;
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
