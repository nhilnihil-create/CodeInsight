#include <bits/stdc++.h>

#define INF INT_MAX
#define ll long long
#define MAX_PRIME 300000

using namespace std;

bool isPrime[MAX_PRIME+1];	//true:?´???°??§?????????false:?´???°??§??????
int sumOfPrime[MAX_PRIME+1]; //?´???????

int main(){
	//?????????
	for(int i = 0;i <= MAX_PRIME;i++){
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	sumOfPrime[0] = 0;

	//?´???°???n <= 123456???????±???????
	for(ll i = 1;i <= MAX_PRIME;i++){
		sumOfPrime[i] = sumOfPrime[i-1];
		if(isPrime[i] == true){
			sumOfPrime[i]++;
			for(ll j = 2; i*j <= MAX_PRIME;j++){
				isPrime[i*j] = false;
			}
		}
	}

	int x;
	while(true){
		scanf("%d",&x);
		if(x == 0)
			break;
		cout << sumOfPrime[2*x] - sumOfPrime[x] << endl;
	}

	return 0;
}