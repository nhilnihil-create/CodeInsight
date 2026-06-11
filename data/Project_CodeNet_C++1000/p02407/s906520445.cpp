#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a;
	int day[a];
	for(int i=1 ;i<=a; i++){
		cin >> b;
		day[i]=b;
	}
	for(int ii=a ;ii>1; ii--){
		cout << day[ii] << " ";
	}
	cout << day[1] << endl;
	return 0;
}