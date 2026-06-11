#include <iostream>
using namespace std;
int main(void){
	int a,b;
	cin >> a >> b;
	if(a > 9 || a < 1 || b > 9 || b < 1){
		cout << "-1" << endl;
		return 0;
	}
	else cout << a*b << endl;
	return 0;

}