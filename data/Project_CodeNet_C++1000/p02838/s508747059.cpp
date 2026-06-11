#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,ch[300010][63],sum[63]={0};
	cin>>n;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ll j=0;
		while(now!=0){
			ch[i][j]=now%2;
			now/=2;
			j++;
		}
	}
	for(ll i=0;i<62;i++){
		for(ll j=0;j<n;j++){
			sum[i]+=ch[j][i];
		}
//		cout <<sum[i];
	}
	ll ans=0;
	for(ll i=0;i<n-1;i++){
		for(ll j=0;j<60;j++){
			sum[j]=sum[j]-ch[i][j];
	//		cout <<sum[j];
		}
	//	cout<<endl;
		ll cnt=0;
		ll keta=1;
		for(ll j=0;j<60;j++){
			if(ch[i][j]){
				cnt+=(n-i-1-sum[j])*keta;
			}
			else{
				cnt+=sum[j]*keta;				
			}
			cnt%=inf;
			keta*=2;
			keta%=inf;
		}
		ans+=cnt;
		ans%=inf;
	}
	cout <<ans;
	// your code goes here
	return 0;
}