#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0;
	cin>>n;
	vi vs(n);
	for(int &x:vs) cin>>x;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			ans+=(vs[i]*vs[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}