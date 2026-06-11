#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	long long min = n;
	//nが何かける何かを求める(このとき二つの数の和を最小になるようにする)。x-1 + y-1が答え
	for(long long i = 1; i < (long long)(sqrt(n)+0.9)+1; i++){
		long long a = i;
		if( n % a != 0) continue;
		long long b = n/a;
		if(a+b-2 < min){
			min = a+b-2;
		}
	}
	cout << min << endl;
	return 0;
}