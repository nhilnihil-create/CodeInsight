#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll ta[2000][2000],yo[2000][2000];
int main() {
	ll h,w;
	cin>>h>>w;
	char ch[2001][2001];
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			char now;
			cin>>now;
			ch[i][j]=now;
		}
	}
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			if(ch[i][j]=='.'){
				yo[i][j]=1;
			}
			if(j!=0&&yo[i][j]!=0){
				yo[i][j]+=yo[i][j-1];
			}
		//	cout << yo[i][j];
		}
		//cout <<endl;
	}
	for(ll i=0;i<w;i++){
		for(ll j=0;j<h;j++){
			if(ch[j][i]=='.'){
				ta[j][i]=1;
			}
			if(j!=0&&ta[j][i]!=0){
				ta[j][i]+=ta[j-1][i];
			}
		}
	}
	for(ll i=0;i<h;i++){
		for(ll j=1;j<w;j++){
			if(yo[i][w-1-j]!=0&&yo[i][w-j]!=0){
				yo[i][w-1-j]=yo[i][w-j];
			}
		}
	}
	for(ll i=0;i<w;i++){
		for(ll j=1;j<h;j++){
			if(ta[h-j-1][i]!=0&&ta[h-j][i]!=0){
				ta[h-j-1][i]=ta[h-j][i];
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			ans=max(ans,ta[i][j]+yo[i][j]);
		}
	}
	cout <<ans-1;
	// your code goes here
	return 0;
}