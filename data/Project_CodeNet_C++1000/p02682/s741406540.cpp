#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c,k; cin>>a>>b>>c>>k;
	int ans=0;
	rep(i,a){
		k--;
		ans++;
		if(k==0) {cout<<ans<<endl; return 0;}
	}
	rep(i,b){
		k--;
		if(k==0) {cout<<ans<<endl; return 0;}
	}
	rep(i,c){
		k--;
		ans--;
		if(k==0) {cout<<ans<<endl; return 0;}
	}
}