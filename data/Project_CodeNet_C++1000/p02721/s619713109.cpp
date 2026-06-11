#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
	ll cnt1[200010]={};
	ll cnt2[200010]={};
int main() {
	string s;
	ll n,k,c;
	cin>>n>>k>>c>>s;

	ll zan=k;
	ll kan=0;
	for(ll i=0;i<n;i++){
		kan--;
		if(kan>0){
			continue;
		}
		if(s[i]=='x'){
			continue;
		}
		cnt1[i]=k-zan+1;
		zan--;
		kan=c+1;
		if(zan==0){
			break;
		}
	}
	zan=k;
	kan=0;
	for(ll i=n-1;i>=0;i--){
		kan--;
		if(kan>0){
			continue;
		}
		if(s[i]=='x'){
			continue;
		}
		cnt2[i]=zan;
		zan--;
		kan=c+1;
		if(zan==0){
			break;
		}
	}
	for(ll i=0;i<n;i++){
		if(cnt1[i]==cnt2[i]&&cnt1[i]!=0){
			cout << i+1<<endl;
		}
	}
	return 0;
}