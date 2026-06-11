#include <iostream>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 9; i++){
		for(int j = 1; j <=9; j++){
			cout << i << "x" << j << "=" << i*j << "\n";
		}
	}

	return 0;
}