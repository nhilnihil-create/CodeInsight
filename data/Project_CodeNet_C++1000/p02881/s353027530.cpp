#include <bits/stdc++.h>
using namespace std; 

#define rep(i,b) for(long long i = 0; i < (b); i++)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
using ll = long long;


void solve() 
{ 

ll n;
cin>>n;
ll x;
ll y;
for(ll i=1;i<=sqrt(n);i++){
	if(n%i==0){
	x=i;	
	y=n/i;
	}
}
cout<<x+y-2;
return ;


}
 

int main(){

		solve();
		cout<<endl;
					
}
		

	

		

 

