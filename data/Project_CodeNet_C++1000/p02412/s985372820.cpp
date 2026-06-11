#include <iostream>
using namespace std;

int main(void){

	int n, x, sum = 0;
	cin >> n >> x;

	do{
		for (int i = 1; i <= n; i++){
			for (int j = i+1; j <= n; j++){
				for (int k = j+1; k <= n; k++){
					if (i + j + k == x)	sum++;
				}
			}
		}
		cout << sum << endl;
		sum = 0;
		cin >> n >> x;
	} while (!(n == 0 && x == 0));


	return 0;
}