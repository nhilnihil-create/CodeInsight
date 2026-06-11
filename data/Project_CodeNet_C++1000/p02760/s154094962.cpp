#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e6+5;
int a[4][4];
int b[4][4];
void solve(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	int n; 
	cin>>n; 
	for(int tc = 1;tc<=n;tc++){
		int x; 
		cin>>x; 
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]==x)b[i][j] = 1;
			}
		}
	}
	bool can = false;
	for(int i=1;i<=3;i++){
		int cnt = 0;
		for(int j=1;j<=3;j++){
			cnt+=b[i][j];
		}
		if(cnt==3)can  = true;
		cnt = 0;
		for(int j=1;j<=3;j++){
			cnt+=b[j][i];
		}
		if(cnt==3)can  = true;

	}
	int cnt = 0;
	for(int i=1;i<=3;i++){
		cnt+=b[i][i];
	}
	if(cnt==3)can  = true;
	cnt = 0;
	for(int i=1;i<=3;i++){
		cnt+=b[i][4-i];
	}
	if(cnt==3)can  = true;
	if(can)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
