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

void solve(int test_case) {//239///F.Sugoroku
	int n;
	cin>>n;
	vector<pair<double,double>> arr(n);
	REP(i,0,n-1)cin>>arr[i].F>>arr[i].S;
	sort(arr.begin(),arr.end());
	double cnt=0;
	double sum = 0;
	do{
		cnt++;
		REP(i,1,n-1) {
			sum+=sqrt(pow(arr[i].F-arr[i-1].F,2)+pow(arr[i].S-arr[i-1].S,2));
		}
		//cerr<<sum<<endl;
	}while(next_permutation(arr.begin(),arr.end()));
	sum/=cnt;
	printf("%.6lf",sum);
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
