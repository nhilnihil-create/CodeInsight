#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main(){
	int n,k;
	cin>>n>>k;
	int h[n]={};
	rep(i,n) cin>>h[i];
	sort(h,h+n);
	if(k>=n){
		cout<<"0"<<endl;
		return 0;
	}
	k=n-k;
	ll ans={};
	rep(i,k) ans+=h[i];
	cout<<ans<<endl;
}