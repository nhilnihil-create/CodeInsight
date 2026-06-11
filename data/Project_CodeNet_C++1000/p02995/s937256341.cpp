#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long ans=b-a+1;
	ans-=((b/c)-((a-1)/c));
	ans-=((b/d)-((a-1)/d));
	long long p=(d*c)/__gcd(d,c);
	ans+=((b/p))-((a-1)/(p));
	cout<<ans<<endl;  
}