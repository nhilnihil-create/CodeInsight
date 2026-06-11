#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int d[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> d[i];
		for(int j = 0; j < i; j++){
			sum += d[j] * d[i];
		}
	}
	
	cout << sum << endl;
}