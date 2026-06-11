#include <iostream>
using namespace std;

int main(){
	int a, b;
	while (cin >> a, cin >> b, !(a==0 && b==0)){
		if (a > b){
			swap(a, b);
		}
			cout << a << " " << b<<"\n";
	}
	return 0;
}