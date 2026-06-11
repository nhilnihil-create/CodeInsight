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
	int test=1;
	//cin>>test;
	rep(tt,test) {
		int n;
		cin>>n;
		int a[n];
		rep(i,n) cin>>a[i];
		int maxl=0;
		int len=0;
		rep(i,n-1){
			if(a[i]>=a[i+1]) {
				len++;
				if(len>maxl) maxl=len;
			}
			else len=0;
		}
		cout<<maxl<<endl;
	}
	return 0;
}
