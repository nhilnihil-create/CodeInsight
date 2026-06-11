#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	vector<vector<int> > ind(1e6+1);
	vector<bool> vis(1e6+1);
	int n,t;
	cin>>n;
	for(int i=0;i<n;i++) cin>>t,ind[t].push_back(i);
	for(int i=0;i<ind.size();i++){
		if(ind[i].size() && !vis[i]){
			for(int j=2*i;j<ind.size();j+=i) vis[j]=1;
		}
		if(ind[i].size() > 1) vis[i]=1;
	}
	int ans=0;
	for(int i=0;i<ind.size();i++) if(ind[i].size() && !vis[i]) ans++;
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
