#include<bits/stdc++.h>
#define ll long long int
#define M 998244353;
using namespace std;
int arr[100006];
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
ll qsm(ll a,ll x)
{
	ll ans=1;
	while(x)
	{
		if(x%2==1)ans=ans*a%M;
		a=a*a%M;
		x/=2;
	}
	return ans;
}
int main(){
 	int n,mx=0;
 	cin>>n;
 	int l;
 	cin>>l;
 	if(l!=0)
 	{
 		cout<<0;
	 	return 0;	
	 }
	 arr[l]++;
 	for(int i=1;i<n;++i)
 	{
 		int d;
 		cin>>d;
 		arr[d]++;
 		mx=max(mx,d);
	 }
	 if(arr[0]!=1){
	 	cout<<0;
	 	return 0;
	 }
	 for(int i=1;i<=mx;++i)
	 {
	 	if(arr[i]==0)
	 	{
	 		cout<<0;
	 		return 0;
		 }
	 }
	 ll sum=1;
	 for(int i=1;i<=mx;++i)
	 {
	 	ll d=arr[i-1];
	 	sum=sum*qsm(d,arr[i])%M;
	 }
	 cout<<sum;
}