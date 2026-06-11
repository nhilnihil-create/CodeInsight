#include <iostream>
using namespace std;

int main() {
	int i,x[10000], y[10000];
	
	for(i=1;i<=10000;i++){
		cin >> x[i] >> y[i];
	}
	for(i=1;i<=10000;i++){
		if(y[i] < x[i]){
			cout << y[i] << " " << x[i] <<endl;	
		}else if(y[i]==0 && x[i]==0){
			break;
		}else{
			cout << x[i] << " " << y[i] <<endl;
		}
	}

	return 0;
}