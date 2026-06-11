#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c;
	scanf("%lld%lld.%lld",&a,&b,&c);
	b = b*100+c;
	cout<<a*b/100;
}