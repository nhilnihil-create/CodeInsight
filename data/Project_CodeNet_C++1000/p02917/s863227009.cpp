#include <iostream> 
 
using namespace std; 
 
int main(){ 
	int n;
	cin >> n;
	int sum = 0;
	int a[n];
	for(int i = 0; i < n-1; i++){
		int b;
		cin >> b;
		if(i == 0) a[i] = b;
		if(a[i] > b) a[i] = b;
		a[i+1] = b;
		sum += a[i];
	}
	sum += a[n-1];
	cout << sum << endl;
	return 0;
} 
