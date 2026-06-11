#include<bits/stdc++.h>
using namespace std;
long long a[100005],mod=1e9+7;
map<long long,long long> m;
int main(){
	long long n,ans=1;
	cin>>n;m[-1]=3;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=ans*(m[a[i]-1]-m[a[i]])%mod;
		m[a[i]]++;
	}
	cout<<ans<<endl;
}