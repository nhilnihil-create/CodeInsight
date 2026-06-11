#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
void solve(){
	cin>>n;
	ans=(n/500)*1000;
	ans+=(n%500)/5*5;
	cout<<ans<<endl;
}
int main(){
	solve();
	return 0;
}