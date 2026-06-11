#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int tmp, suma = 0, sumb = 0;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		suma += tmp;
	}
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		sumb += tmp;
	}
	cout << max(suma, sumb) << endl;
	return 0;
}