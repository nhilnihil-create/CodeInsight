#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

ll gcd(int a,int b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}


int main() {
	ll c,d;
  	cin>>c>>d;
  
  	ll ans=gcd(c,d);

  	
	
 
  
  cout <<c*d/ans<< endl;
  
}