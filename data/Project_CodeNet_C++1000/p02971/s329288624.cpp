#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"
int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	cin>>n;
	ll arr[n];ll lala[n];
	for(auto &i:arr){
		cin>>i;
		lala[x++]=i;
	}
	sort(arr,arr+n);
	
	for(ll i=0;i<n;i++){
		if(arr[n-1]==lala[i])cout<<arr[n-2]<<nw;
		else cout<<arr[n-1]<<nw;
	}

}