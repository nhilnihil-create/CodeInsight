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
ll a,b;
cin>>a>>b;
cout<<lcm(a,b);
}
 

int main(){


		solve();
		cout<<endl;
	
	

					
}
		

	

		

 

