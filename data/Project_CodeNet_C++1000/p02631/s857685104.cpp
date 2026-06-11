#include<bits/stdc++.h>

using namespace std;
#define ll long long
const long long mod=1e9+7;
const int maxn=1e6+7;
ll a[maxn],b[maxn];

//int dp[maxn][maxn];

int main (){
	int n;cin>>n;
    map<ll,ll>mp;
    ll sum=0;
    for(int i=1;i<=n;i++){
			cin>>a[i];
			sum^=a[i];
    }
    for(int i=1;i<=n;i++){
			cout<<(a[i]^sum)<<endl;
    }
	return 0;
}
