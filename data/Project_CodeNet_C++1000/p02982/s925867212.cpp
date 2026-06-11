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
	int n,d;
	cin>>n>>d;
	vector<vector<int>> vs(n,vector<int>(d));
	for(int i=0;i<n;++i){
		for(int j=0;j<d;++j){
			cin>>vs[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;++i){
		for(int k=i+1;k<n;++k){
			int dx=0;
			for(int j=0;j<d;++j){
				int aux = abs(vs[k][j]-vs[i][j]);aux*=aux;
				dx+=aux;
			}
			int xd = sqrt(dx);
			if(xd*xd==dx)
				++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}