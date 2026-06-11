#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;
const int MAX_PRIME = 1000000;


int prime[MAX_PRIME+1];
bool isPrime[MAX_PRIME+1];
int p;

void erats(){
	// primeツδ環スツトツづーツ渉可甘コツ可サ
	fill(isPrime,isPrime+MAX_PRIME,true);
	p = 0;
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i <= MAX_PRIME; i++){
		if(isPrime[i]){
			prime[p++] = i;
		}
		else
			continue;

		// ツづ督づゥツつ「ツづ可つゥツつッツづゥ
		for(int j = 2*i; j <= MAX_PRIME; j+=i){
			isPrime[j] = false;
		}
	}
}


int main(){

	erats();
	int n;
	while(cin>>n&&n!=0){
		int cnt=0;
		for(int i = n+1; i <= 2*n; i++){
			if(isPrime[i])
				cnt++;
		}
		cout<<cnt<<endl;
	}

	return 0;
}