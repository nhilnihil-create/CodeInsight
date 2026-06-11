#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
ll N,K;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>K;
	cout<<(K>1?N-(K-1)-1:0)<<endl;
}