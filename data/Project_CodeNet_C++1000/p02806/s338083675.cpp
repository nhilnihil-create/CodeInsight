#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli n;
	cin>>n;

	vector<string> s(n);
	vector<lli> t(n);
	REP(i,0,n)cin>>s[i]>>t[i];

	string u;
	cin>>u;

	lli sum = 0;
	bool state=false;
	REP(i,0,n){
		if(state)sum+=t[i];
		if(s[i]==u)state=true;
	}
	cout<<sum<<endl;

	return 0;
}