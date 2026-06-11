#include <iostream>
#include<math.h>
using namespace std;
long long c=1e9+7;
long long fast_pow(long long base, long long power){
	long long result =1;
	while(power>0){
		if(power&1) result = (result*base)%c;
		base = (base*base)%c;
		power >>= 1;
	}
	return result;
}
int main(){
	long long n;
	cin>>n;
	cout<<((fast_pow(10,n)-2*fast_pow(9,n)+fast_pow(8,n))%c+c)%c;
	return 0;
}