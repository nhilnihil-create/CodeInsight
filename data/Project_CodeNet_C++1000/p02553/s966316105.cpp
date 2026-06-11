#include <iostream>
using namespace std;
long long a[10];
int main(){
	for(int i = 1;i <= 4;i++)
		cin >> a[i];
	long long res;
	res = a[1]*a[3];
	for(int i = 1;i <= 2;i++){
		for(int j = 3;j <= 4;j++){
			res = max(res,a[i]*a[j]);
		}
	}
	cout << res;
	return 0;
}