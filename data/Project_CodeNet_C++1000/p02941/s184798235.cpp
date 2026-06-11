#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		int ta;
		cin>>ta;
		a.pb(ta);
	}
	for(int i=0;i<n;i++){
		int ta;
		cin>>ta;
		b.pb(ta);
	}
	int ans = 0;
	priority_queue<pair<int,int> > que;
	for(int i=0;i<n;i++){
		if(b[i]<a[i]){
			cout<<-1<<endl;
			return 0;
		}
		if(b[i]>a[i]){
			int lef = (i+n-1)%n;
			int rig = (i+n+1)%n;
			int su = b[lef]+b[rig];
			if( b[i] > su ) que.push(mp(b[i],i));
		}
	}
	while(!que.empty()){
		pair<int,int> tp = que.top();que.pop();
		int idx = tp.second;
		int lef = (idx+n-1)%n;
		int rig = (idx+n+1)%n;
		int su = b[lef]+b[rig];
		int det = max(a[idx],b[idx]%su);
		ans +=  ( b[idx]-det )/su;
		b[idx] -= ( b[idx]-det )/su *su;
		int nidx = lef;
		if(b[nidx]>a[nidx]){
			int le = (nidx+n-1)%n;
			int ri = (nidx+n+1)%n;
			int sus = b[le]+b[ri];
			if( b[nidx] > sus ) que.push(mp(b[nidx],nidx));
		}
		nidx = rig;
		if(b[nidx]>a[nidx]){
			int le = (nidx+n-1)%n;
			int ri = (nidx+n+1)%n;
			int sus = b[le]+b[ri];
			if( b[nidx] > sus ) que.push(mp(b[nidx],nidx));
		}
	}
	bool fl = true;
	for(int i=0;i<n;i++){
		if(a[i] != b[i])fl=false;
	}
	if(fl)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}