#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[114514],b[114514];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<=n;i++)cin>>a[i];
	b[n]=a[n];
	for(int i=n-1;i>=0;i--){
		b[i]=a[i];
		b[i]+=b[i+1];
	}
	ll ans=1,num=1;
	if(a[0]==0){
		for(int i=1;i<=n;i++){
			num=min(2*num,b[i]);
			ans+=num;
			num-=a[i];
			if(num<0||(i!=n&&num==0)){
				cout<<-1;
				return 0;
			}
		}
		cout<<ans;
	}else if(a[0]==1)cout<<(n==0?1:-1);
	else cout<<-1;
	return 0;
}
