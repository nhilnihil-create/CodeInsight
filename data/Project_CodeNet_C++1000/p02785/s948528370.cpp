#include <bits/stdc++.h>
using namespace std; 

#define rep(i,b) for(long long i = 0; i < (b); i++)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
using ll = long long;

ll lcm(ll a,ll b){
	
	return (a*b)/(__gcd(a,b));
}


void solve() 
{ 
int n,k;
cin>>n>>k;
vector<int> v(n);
rep(i,n){
	cin>>v[i];
}
sort(all(v));
if(k>=n){
	cout<<0;
	return ;
}
ll sum=0;
for(int i=0;i<n-k;i++){
	sum=sum+v[i];
}
cout<<sum;
}
int main(){


		solve();
		cout<<endl;
		


	
					
}
		

	

		

 

