#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;


const int END_OF_INPUT = 0;


bool check_prime(int s){
	if (s == 2) return true;
	for(int i = 2; i <= ((int)sqrt(s)+1); ++i){
		if (s % i == 0){
			return false;
		}
	}
	return true;
}

int main() {
	int input_num, num_of_primes;
	
	while (cin >> input_num && input_num != END_OF_INPUT){
		num_of_primes = 0;
		for (int i = input_num + 1; i <= input_num * 2; ++i){
			num_of_primes = check_prime(i) ? num_of_primes + 1: num_of_primes;
		}
		cout << num_of_primes << endl;
	}


}