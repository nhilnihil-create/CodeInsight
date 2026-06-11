#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	long int sum = 0;
	cin >> n ;
	int* a = new int[n];
	for(int i = 0; i < n ; i++){
		cin >> a[i];
		sum +=a[i];

	}
	sort(a,a + n);
	cout << a[0] << " " << a[ n - 1] << " " << sum << endl;

	
	return 0;
}