#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define MOD 1e9+7
#define ll long long
#define all(x) x.begin(),x.end()
#define vvl vector<vector<ll>>
#define vl  vector<ll>
#define rep(i,sta,end) for(ll i=sta;i<end;i++)
//name[i]   -> vl  name(i)
//name[i][j]-> vvl name(i,vl(j))
//or-> ||

signed main(){
	acc_io;
	ll n;
	cin>>n;
  	if(n%2!=0)n++;
	cout<<(n/2-1)<<endl;
	return 0;
}
