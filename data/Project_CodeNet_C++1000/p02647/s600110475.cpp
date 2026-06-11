#include<bits/stdc++.h>
#include<iomanip>
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define ld long double
#define pb push_back
#define mod 1000000007
typedef long long int ll;
using namespace std;
int main(void){
	fast;
	int n,k,i,j;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(j=1;j<=min(k,42);j++){
	int b[n]={0};
	for(i=0;i<n;i++){
		int l=max(0,i-a[i]);
		int r=min(n-1,i+a[i]);
		b[l]++;
		if(r<n-1)
		b[r+1]--;
	}
	for(i=1;i<n;i++)
	b[i]=b[i-1]+b[i];
	for(i=0;i<n;i++)
	a[i]=b[i];
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
	
