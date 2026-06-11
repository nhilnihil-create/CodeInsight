#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int df[214514], ds[214514][2]; // 0:mada, 1:nukasi
signed main(){
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	string st;
	cin>>st;
	a--;b--;c--;d--;
	df[b] = true;
	int mf = -1;
	for(int i=b;i<n;i++){
		if( df[i] ){
			if( i+1 <= d && st[i+1] == '.' ){ df[i+1] = true; mf = max(mf,i+1);}
			if( i+2 <= d && st[i+2] == '.' ){ df[i+2] = true; mf = max(mf,i+2);}
		}
	}
	ds[a][0] = true;
	for(int i=a;i<n;i++){
		if( ds[i][0] ){
			if( i+1 <= c && st[i+1] == '.' && mf > i+1 ){ ds[i+1][0] = true; }
			if( i+2 <= c && st[i+2] == '.' && mf > i+2 ){ ds[i+2][0] = true; }
			if( i+2 <= c && st[i+2] == '.' && df[i+1] ){ ds[i+2][1] = true; }
		}
		if( ds[i][1] ){
			if( i+1 <= c && st[i+1] == '.' ){ ds[i+1][1] = true; }
			if( i+2 <= c && st[i+2] == '.' ){ ds[i+2][1] = true; }
		}
	}
	if( df[d] && ( ds[c][0] || ds[c][1] ) ){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}