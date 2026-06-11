//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
ll M;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sm=0,dsm=0;
	cin>>M;
	REP(i,M){
		ll d,c;
		cin>>d>>c;
		dsm+=c;
		sm+=d*c;
	}
	cout<<dsm-1+(sm-1)/9<<endl;
}