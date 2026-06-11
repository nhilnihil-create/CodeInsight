#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
using namespace std;

int main(){
	int n;	cin>>n;
	int a[100010];
	vector<int> L;
	REP(i,0,n) cin>>a[i];
	L.push_back(a[0]);
	REP(i,1,n){
		if(L.back()<a[i])	L.push_back(a[i]);
		else	*lower_bound(L.begin(),L.end(),a[i])=a[i];
	}
	p(L.size());
	return 0;
}