#include <iostream>
#include <algorithm>
#include <complex>

using namespace std;

bool IsPrime(int num);

int main(){
	int n;
	while(cin >> n, n){
		int count = 0;
		for(int i = n+1; i <= 2*n; i++){
			if(IsPrime(i)){
				count++;
			}
		}
		
		cout << count << endl;
	}
	return 0;
}

bool IsPrime(int num){
	if(num < 2){
		return false;
	}else if(num == 2){
		return true;
	}else if(num % 2 == 0){
		return false;
	}
	
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2){
		if(num % i == 0){
			return false;
		}
	}
	
	return true;
}
