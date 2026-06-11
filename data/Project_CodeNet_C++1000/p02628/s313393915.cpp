#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main(){
	int n,k;
	cin>>n>>k;
	int p[n]={};
	rep(i,n) cin>>p[i];
	sort(p,p+n);
	int ans=0;
	rep(i,k) ans+=p[i];
	cout<<ans<<endl;
}