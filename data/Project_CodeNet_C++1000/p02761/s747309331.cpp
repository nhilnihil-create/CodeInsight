#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m; cin>>n>>m;
	vector<pair<int,char>> vp(m);
	for(int i=0; i<m; i++){
		int a; char b; cin>>a>>b;
		vp[i]=make_pair(a-1,b);
	}
	int low, lim;
	if(n==1) low=0, lim=10;
	else if(n==2) low=10, lim=100;
	else low=100, lim=1000;
	for(int i=low; i<lim; i++){
		bool flg=true;
		string s=to_string(i);
		for(int j=0; j<m; j++){
			if(s[vp[j].first]!=vp[j].second) flg=false;
		}
		if(flg) {cout<<i<<endl; return 0;}
	}
	cout<<-1<<endl;
}