#include <iostream>

using namespace std;

int main(){
	bool flg = false;
	for(int i = 0; i < 3; i++){
		char c;
		cin >> c;
		if(c == '7') flg = true;
	}
	if(flg)cout << "Yes";
	else cout << "No";
	
	cout << endl;
}