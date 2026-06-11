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
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

signed  main(){
	int t=1;
	//cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vpi std(n);
		rep(i,n) {
			cin>>std[i].first;
			std[i].second=i+1;
		}
		sort(std.begin(), std.end());
		rep(i,n) cout<<std[i].second<<" ";
		cout<<endl;
	}
	return 0;
}