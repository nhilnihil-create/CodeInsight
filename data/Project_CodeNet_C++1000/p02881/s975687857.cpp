#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void){
	long long n;
	cin >> n;
	long long sum=n-1;
	for(long long i=sqrt(n); i>1; i--){
		if(n%i==0){
			sum = min(sum, i + n/i -2);
		}
	}
	cout << sum << endl;
}