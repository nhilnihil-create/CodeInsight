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
		int b[n];
		int c[n];
		int s=0;
		rep(i,n) cin>>a[i];
		rep(i,n) cin>>b[i];
		rep(i,n) {if(i==0) continue; cin>>c[i];}
		rep(i,n) {
			s+=b[a[i]-1];
			if(i==0) continue;
			if(a[i]==a[i-1]+1 ){
				s+=c[a[i]-1];
			}

		}
		cout<<s<<endl;
	}
	return 0;
}
