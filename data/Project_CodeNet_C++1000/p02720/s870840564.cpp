#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll k,cnt;
vector<ll>ans;
void dep(ll sum,ll keta,ll nowke){
	if(keta==nowke){
		ans.push_back(sum);
		return ;
	}
	ll now=sum%10;
	if(now>=1){
		dep(sum*10+now-1,keta,nowke+1);
	}
	dep(sum*10+now,keta,nowke+1);
	if(now<9){
		dep(sum*10+now+1,keta,nowke+1);
	}
}
int main() {
	cin>>k;
	for(ll i=1;i<=13;i++){
		for(ll j=1;j<=9;j++){
			dep(j,i,1);
		}
	}
	for(ll i=k-1;i<=k-1;i++){
	cout << ans[i]<<endl;
		
	}
	return 0;
}