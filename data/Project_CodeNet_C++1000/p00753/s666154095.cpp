#include <cstdio>
#include <cstring>
using namespace std;

int N;

const int MAX_SIZE = 1000000;
bool isPrime[MAX_SIZE];
void seive(){
	memset(isPrime, -1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i*i<MAX_SIZE; i++)if(isPrime[i]){
		for(int j=i<<1; j<MAX_SIZE; j+=i){
			isPrime[j] = false;
		}
	}
}

int solve(){
	int ret = 0;
	for(int i=N+1; i<=2*N; i++)if(isPrime[i]){
		ret++;
	}
	return ret;
}

int main(){
	seive();
	while(scanf("%d\n",&N), N){
		printf("%d\n",solve());
	}
	return 0;
}