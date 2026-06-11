#include <iostream>
 
using namespace std;
 
int main(){
	long long N, M;
	cin >> N >> M;
 
	if (M % 2){
		for (int i = 0; i < M/2; i++){
			cout << i + 1 << " " << M - i << endl;
		}
		for (int i = 0; i < M/2 + 1; i++){
			cout << M + i + 1 << " " << 2 * M - i + 1 << endl;
		}
	} else {
		for (int i = 0; i < M/2; i++){
			cout << i + 1 << " " << M - i + 1 << endl;
			cout << M + i + 2 << " " << 2 * M - i + 1 << endl;
		}
	}
 
	return 0;
}