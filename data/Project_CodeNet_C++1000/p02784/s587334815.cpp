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
int h,n;
cin>>h>>n;
ll sum=0;
rep(i,n){
	int x;
	cin>>x;
	sum=sum+x;
}
if(sum>=h)
{
cout<<"Yes";	
return ;
}


cout<<"No";
}
int main(){


		solve();
		cout<<endl;
		


	
					
}
		

	

		

 

