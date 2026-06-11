#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<string> vs(n);
	vector<int> vi(n);
	rep(i,n) {cin>>vs[i]; cin>>vi[i];}
	string x; cin>>x;
	
	auto itr=find(vs.begin(),vs.end(),x);
	int idx=distance(vs.begin(),itr);
	
	int ans=0;
	for(int i=idx+1; i<n; i++){
		ans+=vi[i];
	}
	cout<<ans<<endl;
}