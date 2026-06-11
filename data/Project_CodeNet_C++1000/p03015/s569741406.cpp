#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7,num,ans;
string s;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return res%mod;
}
int main(){
	cin>>s;
	ll n=s.length();
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			ans=(ans%mod+qpow(2,num)%mod*qpow(3,n-i-1)%mod)%mod;
			num++;
		}
	}
	cout<<(ans%mod+qpow(2,num)%mod)%mod<<endl;

}