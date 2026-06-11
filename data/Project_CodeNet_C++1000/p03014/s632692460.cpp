#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll h,w;
ll H[2010][2010];
ll W[2010][2010];
char ch[2010][2010];
int main() {
	cin>>h>>w;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			cin>>ch[i][j];
		}
	}
	for(ll i=0;i<h;i++){
		ll cnt=0;
		for(ll j=0;j<w;j++){
			if(ch[i][j]=='#'){
				cnt=0;
				continue;
			}
			cnt++;
			H[i][j]=cnt;
		}
		cnt=H[i][w-1];
		for(ll j=w-1;j>=0;j--){
			if(ch[i][j]=='#'){
				cnt=0;
				continue;
			}
			cnt=max(cnt,H[i][j]);
			H[i][j]=cnt;
		}
	}
	for(ll i=0;i<w;i++){
		ll cnt=0;
		for(ll j=0;j<h;j++){
			if(ch[j][i]=='#'){
				cnt=0;
				continue;
			}
			cnt++;
			W[j][i]=cnt;
		}
		cnt=W[h-1][i];
		for(ll j=h-1;j>=0;j--){
			if(ch[j][i]=='#'){
				cnt=0;
				continue;
			}
			cnt=max(cnt,W[j][i]);
			W[j][i]=cnt;
		}
	}
	ll ans=0;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
		//	cout << W[i][j];
			ans=max(ans,H[i][j]+W[i][j]);
		}
	//	cout <<endl;
	}
	cout <<ans-1;
	// your code goes here
	return 0;
}