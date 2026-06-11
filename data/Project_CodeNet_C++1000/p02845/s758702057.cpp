#include<bits/stdc++.h>
using namespace std;
long n,a,c[1<<17],MOD=1e9+7,ans=1,i;
int main(void){
	cin>>n;
	c[0]=3;
	for(i=0;i<n;i++){
		cin>>a;
		ans=ans*c[a]%MOD;
		c[a]--;
		c[a+1]++;
	}
	cout<<ans<<endl;
}
