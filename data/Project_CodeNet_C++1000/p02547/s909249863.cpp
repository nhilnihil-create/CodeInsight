#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int32_t main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int ans = INT_MIN;
	int count  = 0;
	for(int i=0;i<n;i++){
		if(a[i]==b[i])
			count++;
		else{
			ans = max(ans, count);
			count = 0;
		}
	}
	ans = max(ans, count);
	if(ans >= 3)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}