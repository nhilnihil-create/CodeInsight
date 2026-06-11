#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long int ll;
const int mod = 1000000007;


int main(){
	ll h,ans=1;
	cin>>h;
	ll a=1;
	while(h>1){
		h/=2;
		a*=2;
		ans+=a;
	}
	cout<<ans<<endl;
}