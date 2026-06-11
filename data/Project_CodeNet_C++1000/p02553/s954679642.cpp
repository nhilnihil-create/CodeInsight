#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	long long a,b,c,d,t,n;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	t=max(a*c,a*d);
	n=max(b*c,b*d); 
		cout<<max(t,n)<<endl;	
	return 0;
}
