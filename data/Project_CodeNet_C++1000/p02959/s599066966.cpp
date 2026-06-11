#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n+1];
	int b[n];
	
	long long total = 0;
	
	for(int i = 0; i < n+1; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		if(a[i] <= b[i]) {
			total += a[i];
			b[i] -= a[i];
			a[i] = 0;
			
			if(a[i+1] <= b[i]){
				total += a[i+1];
				a[i+1] = 0;
			}else{
				total += b[i];
				a[i+1] -= b[i];
			}
		}else{
			total += b[i];
			a[i] -= b[i];
		}
	}
	cout << total << endl;
	return 0;
}