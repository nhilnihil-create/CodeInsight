#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int MAX_N = 1000000;

bitset<MAX_N> sieve;
vector<int> primes;
void eratosthenes(){
	sieve[0] = sieve[1] = true;
	for(int i = 2; i < MAX_N; ++i){
		if(sieve[i]){ continue; }
		primes.push_back(i);
		for(int j = i + i; j < MAX_N; j += i){ sieve[j] = true; }
	}
}

int main(){
	eratosthenes();
	while(true){
		int n;
		cin >> n;
		if(n == 0){ break; }
		int answer = 0;
		for(int i = n + 1; i <= 2 * n; ++i){
			if(!sieve[i]){ ++answer; }
		}
		cout << answer << endl;
	}
	return 0;
}