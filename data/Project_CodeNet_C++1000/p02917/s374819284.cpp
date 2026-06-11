#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=0;i<n;i++)
#define repa(i,j,n) for(int i=j;i<n;i++)
//#define v.all() v.begin(),v.end()
#define repr(i,n) for(int i=n;i>=0;i--)
#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>

signed  main(){
	int t=1;
	//cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n];
		int b[n-1];
		rep(i,n-1) cin>>b[i];
		a[0]=b[0];
		rep(i,n-1){
			if(i==n-2) a[i+1]=b[i];
			else a[i+1]=min(b[i+1],b[i]);
		}
		int s=0;
		rep(i,n) s+=a[i];
		cout<<s<<endl;

	}
	return 0;
}
