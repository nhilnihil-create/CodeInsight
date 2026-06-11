#include <iostream>
using namespace std;
int main(void){
	long long  n;
	cin >>n;
	long long  min=n+1;
	long long  tmp;
	for(long long i=1;i*i<=n;i++){
		long long  j;
		if(n%i==0){
			j = n/i;
			tmp  = j+i-2;
		}
		if(min>tmp)min=tmp;
	}
	cout <<min<<endl;
	return 0;

}