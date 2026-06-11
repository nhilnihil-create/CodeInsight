#include<iostream>
using namespace std;
int c;
int sub(int n, int x, int s, int sum){
	int i;
	if (n == 0){
		if (s == sum){
			c++;
		}
		return 0;
	}
	for (i = x; i <= 10 - n; i++){
		sub(n - 1, i + 1, s, sum+i);
	}
}
int main(void){
	int i, n, s, sum;
	while (1){
		cin >> n >> s;
		if (n == 0 && s == 0){ break; }
		c = 0;
		sub(n, 0, s, 0);
		cout << c << endl;
	}
	return 0;
}