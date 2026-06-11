#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
ll X,Y;
ll mny[206];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans=0;
	cin>>X>>Y;
	REP(i,3)mny[i+1]=100000*(3-i);
	ans+=mny[X]+mny[Y];
	if(X==1&&Y==1){
		ans+=400000;
	}
	cout<<ans<<endl;
}