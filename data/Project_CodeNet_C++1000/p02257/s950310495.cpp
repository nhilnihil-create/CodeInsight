#include <iostream>

using namespace std;;

int main() {
	long long int n,a[10000],j,i,p;
	p = 0;
	cin >> n;
	for  (i = 0; i < n; i++){
		cin >> a[i];
		for (j = 2; j*j <= a[i]; j++) {
			if(a[i]%j==0){
				p += 1;
				break;
			}
		}
	}
	
	cout << n-p << endl;
	return 0;
}