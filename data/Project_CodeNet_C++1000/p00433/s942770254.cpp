#include <iostream>
using namespace std;

int main() {
	int a[4], b[4], S=0, T=0;
	for(int i=0; i<4; i++){
		cin >> a[i];
		S += a[i];
	}
	for(int j=0; j<4; j++){
		cin >> b[j];
		T += b[j];
	}
	if(S>=T) cout << S << endl;
	else cout << T << endl;
	return 0;
}
