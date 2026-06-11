#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,ans=1;
	cin>>a>>b;
	if(b==1) cout<<0<<endl;
	else {
	while(ans*a-(ans-1)<b){
		ans++;
	}
	cout<<ans<<endl;
	}
}