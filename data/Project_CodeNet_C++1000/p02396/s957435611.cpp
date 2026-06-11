#include <iostream>
using namespace std;

int main() {
	int i, x[10000];
	
	for(i=1;i<=10000; i++){
		cin >> x[i];
	}
	for(i=1; i<=10000; i++){
		if(x[i] == 0){
			break;	
		}
		cout << "Case " << i <<": "<< x[i] << endl;
	}
	return 0;
}