#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	int ans=m;
	for(int i=0;i<=n-m;i++){
		int p=0;
		for(int j=0;j<m;j++){
			if(s[i+j]!=t[j]) p++;
		}
		ans=min(ans,p);
	}
	cout<<ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
 
}