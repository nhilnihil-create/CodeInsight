#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int N;
	bool prime[300000];
	prime[0] = prime[1] = false;
	for(int i=2;i<300000;i++) prime[i] = true;
	for(int i=2;i<300000;i++){
		if(!prime[i]) continue;
		for(int j=2*i;j<300000;j+=i) prime[j] = false;
	}
	while(cin >> N, N){
		int res = 0;
		for(int i=N+1;i<=2*N;i++) res += prime[i];
		cout << res << endl;
	}
}