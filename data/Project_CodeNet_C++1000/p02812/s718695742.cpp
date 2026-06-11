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
string s;
cin>>s;
int ans=0;
rep(i,n){
	
	if(i+1<n&&s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
		ans++;
	}
}
cout<<ans;
}
 

int main(){


		solve();
		cout<<endl;
	

	
					
}
		

	

		

 

