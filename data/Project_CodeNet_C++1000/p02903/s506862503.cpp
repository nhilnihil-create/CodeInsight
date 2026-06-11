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

	lli h,w,a,b;
	cin>>h>>w>>a>>b;

	REP(i,0,h){
		REP(j,0,w){
			cout<<(((i<b)^(j<a))?1:0);
		}
		cout<<endl;
	}

	return 0;
}