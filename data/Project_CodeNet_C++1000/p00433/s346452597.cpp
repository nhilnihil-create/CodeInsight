#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
	int tmp,S=0,T=0;
	for(int i; i<4; i++){
		cin >> tmp;
		S+=tmp;
	}
	for(int i; i<4; i++){
		cin >> tmp;
		T+=tmp;
	}
	if(S>T)
		cout << S << endl;
	else
		cout << T << endl;
	return 0;
}