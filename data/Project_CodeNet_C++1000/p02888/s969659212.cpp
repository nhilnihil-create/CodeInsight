#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
using namespace std;
ll ans;
signed main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<int> l(n);
	for(int i=0;i<n;i++) cin>>l[i];
	sort(all(l));
	for(int i=0;i+2<n;i++){
		for(int j=i+1;j+1<n;j++){
			int a=l[i],b=l[j];
			ans+=lower_bound(all(l),a+b)-l.begin()-1-j;
		}
	}
	cout<<ans;
	re 0;
}