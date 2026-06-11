#include<bits/stdc++.h>

using namespace std;
#define ll long long
const long long mod=1e9+7;
const int maxn=1e3+7;
int a[maxn],b[maxn];

int dp[maxn][maxn];

int main (){
	int n;cin>>n;
    map<ll,ll>mp;
    ll sum=0;
    for(int i=1;i<=n;i++){
		ll x;cin>>x;
		mp[x]++;
		sum+=x;
    }
    int q;cin>>q;
    while(q--){
		ll a,b;cin>>a>>b;
		sum-=mp[a]*a;
		sum+=mp[a]*b;
		mp[b]+=mp[a];
		mp[a]=0;
		cout<<sum<<endl;
    }
	return 0;
}
