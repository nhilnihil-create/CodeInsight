#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	
	int num = a+b;
	if(num % 2 != 0) cout << "IMPOSSIBLE";
	else cout << num / 2;
	
	cout << endl;
	return 0;
}