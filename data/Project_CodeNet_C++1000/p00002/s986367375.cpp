#include <iostream>

using namespace std;

int main(){
	int a, b,x,cnt;	//?????°
	
	while (cin >> a >> b){
		cnt = 0;
		x = a + b;

		while (x > 0){
			cnt++;
			x /= 10;
		}

		cout << cnt << endl;
	}
	return 0;
}