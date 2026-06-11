#include <iostream>

using namespace std;

const int COINS[] = { 500, 100, 50, 10, 5, 1 };

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0){ break; }
		n = 1000 - n;
		int answer = 0;
		for(int i = 0; n > 0; i++){
			while(n >= COINS[i]){
				n -= COINS[i];
				answer++;
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}