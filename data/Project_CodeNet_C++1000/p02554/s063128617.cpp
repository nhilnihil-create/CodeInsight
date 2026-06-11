#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MO=1e9+7;
ll qmi(ll a,ll b) {
	ll res=1;
	while(b!=0){
		if(b%2==1){
			res=res*a%MO;
		}
		a=a*a%MO;
		b/=2;
	}
	return res;
}

int main(){
	ll n;
	cin>>n;
	cout<<((qmi(10ll,n)-2*qmi(9ll,n)+qmi(8ll,n))%MO+MO)%MO;
	return 0;
}