#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	char pre_char;
	int count = 1;
	cin >> pre_char;
	for(int i = 1; i < n; i++){
		char c;
		cin >> c;
		if(pre_char != c) count++;
		pre_char = c;
	}
	
	cout << count << endl;
}