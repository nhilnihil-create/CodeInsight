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
	int h,w,k,total=0;
	cin>>h>>w>>k;
	vector<vector<int>> arr(h,vi(w,0));
	vi rows(h,0),cols(w,0);
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			char c;
			cin>>c;
			if(c=='#')arr[i][j]++,total++,cols[j]++,rows[i]++;
		}
	}
	int ans = 0;
	//set<set<pair<int,int>>> crs;
	vi all(h+w);
	for(int i=0;i<h+w;i++)all[i]=i;
	//int icnt=0;
	for(int i=0;i<1<<(h+w);i++) {
		//icnt++;
		vi r,c;
		for(int j=0;j<h+w;j++) {
			if((i>>j)&1) {
				if(j<h)r.PUB(j);//,cerr<<j;
				else c.PUB(j-h);//,cerr<<j-h;
			}
		}
		//set<pair<int,int>> icrs;
		int del = 0;
		// if(r.size()>0&&c.size()>0){
			for(int ri:r) {
				for(int ci:c) {
					del-=arr[ri][ci];
					//icrs.insert({ri,ci});
				}
			}
		// } else if(r.size()>0) {
			for(int ri:r){del+=rows[ri];}//icrs.insert({ri,-1});}
		// } else if(c.size()>0)
			for(int ci:c)del+=cols[ci];//,icrs.insert({-1,ci});
		if(total-del==k){
			ans++;
		}
		//crs.insert(icrs);
	}
	cout<<ans;
	//cerr<<crs.size();
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
