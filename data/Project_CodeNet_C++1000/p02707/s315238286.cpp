#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
	ll n,x; cin>>n;
	ll cnt[n+1]={0};
	for(int i=0;i<n-1;i++) cin>>x,cnt[x]++;
	for(int i=1;i<=n;i++) cout<<cnt[i]<<endl;
}
