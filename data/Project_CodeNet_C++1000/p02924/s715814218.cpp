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
		int t=n*(n-1);
      	t/=2;
      cout<<t<<endl;
	}
	return 0;
}
