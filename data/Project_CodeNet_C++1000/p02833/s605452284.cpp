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
ll n;
cin>>n;
ll i=10;
ll ans=0;
if(n%2){
	cout<<0;
	return ;
}
while((n/i)>0){
	
	ans=ans+n/i;
	i=i*5;
}
cout<<ans;

}
 

int main(){


		solve();
		cout<<endl;
	
					
}
		

	

		

 

