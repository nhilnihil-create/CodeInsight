#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

bool isGood(lli n,lli m,lli v,lli p,vector<lli> &a,lli x){
	if(x<p)return true;
	lli now = a[x]+m;
	if(a[p-1]>now)return false;
	lli score = 0;
	score += (p-1)*m;
	score += (n-x)*m;
	for(lli i=p-1;i<x;i++){
		score += min(m,max(0LL,now-a[i]));
	}
	return score >= m*v;
}

signed main(){

	lli n,m,v,p;
	cin>>n>>m>>v>>p;
	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];
	sort(a.rbegin(),a.rend());

	lli ok=-1;
	lli ng = n;
	while(abs(ok-ng)>1){
		lli mid = (ok+ng)/2;
		if(isGood(n,m,v,p,a,mid))ok=mid;
		else ng = mid;
	}

	cout<<ok+1<<endl;

	return 0;
}