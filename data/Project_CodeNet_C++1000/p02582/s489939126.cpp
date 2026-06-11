#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int ans=0,a=0;
	rep(i,3){
		char k; cin>>k;
		if(k=='R'){
			a++; 
			//cout<<a<<endl;
		}
		else{ ans=max(a,ans); a=0;}
	}
	ans=max(a,ans);
	cout<<ans<<endl;
}