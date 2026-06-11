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
string a,b;
cin>>a>>b;
string out="";
int flag=0;
int i=0;
int j=0;
while(i<=n){
	if(flag==0){
		out=out+a[i];
		i++;
			flag=!flag;
	}
		else{
			out=out+b[j];
			j++;
			flag=!flag;
		}
}
out.resize(2*n);
cout<<out;
}
 

int main(){


		solve();
		cout<<endl;
	
	

					
}
		

	

		

 

