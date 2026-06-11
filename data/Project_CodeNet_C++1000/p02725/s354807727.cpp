#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int k,n; cin>>k>>n;
	int maxa=0;
	int a[n]={};
	rep(i,n) cin>>a[i];
	rep(i,n-1){
		maxa=max(maxa,a[i+1]-a[i]);
	}
	maxa=max(maxa,k-a[n-1]+a[0]);
	cout<<k-maxa<<endl;
		
}
		
	
