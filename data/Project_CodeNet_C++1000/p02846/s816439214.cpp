#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	long long t[2], a[2], b[2];
	long long cnt = 0;
	bool flag = false;
	long long dif_total, dif_mid;
	long long ans = 0;

	// input
	for(int i=0; i<2; i++){
		cin >> t[i];
	}
	for(int i=0; i<2; i++){
		cin >> a[i];
		a[i] = a[i]*t[i];
	}
	for(int i=0; i<2; i++){
		cin >> b[i];
		b[i] = b[i]*t[i];
	}

	// infinity pattern
	if(a[0]+a[1] == b[0]+b[1]){
		cout << "infinity" << endl;
		return 0;
	}

	dif_total = a[0]+a[1]-b[0]-b[1];
	dif_mid = a[0]-b[0];
	// zero pattern
	if((dif_total>0&&dif_mid>0) || (dif_total<0&&dif_mid<0)){
		cout << 0 << endl;
		return 0;
	}

	dif_total = labs(a[0]+a[1]-b[0]-b[1]);
	dif_mid = labs(a[0]-b[0]);
	if(dif_mid%dif_total == 0){
	cout << 1 + (dif_mid/dif_total)*2 -1 << endl;

	}else{
	cout << 1 + (dif_mid/dif_total)*2 << endl;

	}

	return 0;
}