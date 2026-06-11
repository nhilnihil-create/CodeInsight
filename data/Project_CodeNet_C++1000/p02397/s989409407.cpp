#include<iostream>
using namespace std;
int main(){
	int a,b;
	while(1){
		cin >> a >> b;
		if(a+b == 0)break;
		if(a>b){
			swap(a,b);
		}
		cout << a << " " << b << endl;
	}
	return 0;
}