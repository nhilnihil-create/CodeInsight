#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				sum+=gcd(i,gcd(j,k));
				//cout<<i<<" "<<j<<" "<<k<<'\n';
			}
		}
	}
	cout<<sum;
	return 0;
}
