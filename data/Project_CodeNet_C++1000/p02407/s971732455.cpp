#include <iostream>
using namespace std;

int main(void){
	int ary[101], n;
	cin >>n;
	for(int i=0; i<n; i++){
		cin >>ary[i];
	}
	for(int i=n-1; i>0; i--){
		cout <<ary[i] <<" ";
	}
	cout <<ary[0] <<endl;
	return 0;
}