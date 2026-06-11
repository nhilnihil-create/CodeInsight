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

void solve(int test_case) {//227
	string s;
	cin>>s;
	ll sum = 0;
	int last = 0;
	if(s[0]=='>'){last = 1;sum=1;}
	REP(i,0,s.length()-1) {
		ll cnt = 1;
		REP(j,i+1,s.length()-1)if(s[j]!=s[i])break;else cnt++;
		if(last==0) {
			sum+=cnt*(cnt+1)/2;
			last = cnt;
		} else {
			if(last<=cnt) {
				sum-=last;
				sum+=cnt*(cnt+1)/2;
			} else {
				sum+=cnt*(cnt+1)/2;
				sum-=cnt;
			}
			last = 0;
		}
		i+=cnt-1;
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
