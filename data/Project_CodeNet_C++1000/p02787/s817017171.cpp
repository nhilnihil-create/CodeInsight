#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,n;
	cin>>h>>n;
	ll ah[1002],bm[1002];
	ll ch[20010];
	ch[0]=0;
	for(ll i=1;i<20010;i++){
		ch[i]=INF;
	}	
	for(ll i=0;i<n;i++){
		cin>>ah[i]>>bm[i];
	}
	ll ans=INF;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<n;j++){
			ch[i+ah[j]]=min(ch[i+ah[j]],ch[i]+bm[j]);
			if(i+ah[j]>=h){
			ans=min(ans,ch[i+ah[j]]);
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}