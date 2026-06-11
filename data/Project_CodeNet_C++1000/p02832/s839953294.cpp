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

int n;
cin>>n;
vector<int> v(n);
rep(i,n){
	cin>>v[i];
}
int j=1;
int ans=0;
rep(i,n){
	if(v[i]==j){
		ans++;
		j++;
	}
}
if(ans==0){
	cout<<-1;
	return ;
}
cout<<n-ans;
}
 

int main(){


		solve();
		cout<<endl;
	
					
}
		

	

		

 

