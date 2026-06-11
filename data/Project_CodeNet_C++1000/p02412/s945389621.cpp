#include <iostream>

using namespace std;

int main(){

	int n , x;
	int sum;

	while(1){

		int ans = 0;
		cin >> n >> x;
		if(n == 0 && x == 0) break;

		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				for(int k = j+1; k <= n; k++){
					if(i < x || j < x || k < x){
						sum = i + j + k;
						if(sum == x){
							ans++;
						}
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}