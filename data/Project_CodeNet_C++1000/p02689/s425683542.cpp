#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
	 ll n,t,i,p,q,c=0,l; cin>>n>>t; ll a[n+1]; ll b[n+1]={0};
	 for(i=1;i<=n;i++) {cin>>a[i];}
	 while(t--)
	 {
	     cin>>p>>q;
	     b[p]=max(b[p],a[q]);
	     b[q]=max(b[q],a[p]);
	 }
	 for(i=1;i<=n;i++)
	 { 
	     if (a[i]>b[i]) {c++;}
	 } cout<<c;
	return 0;
}