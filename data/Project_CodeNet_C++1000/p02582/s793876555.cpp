#include <iostream>
#include <string>

using namespace std;
int main() {
	string d;
	cin >> d;
	int max,curr;
	max = 0;
	curr = 0;
	for(int i = 0; i <3; i++){
		if (d[i] == 'R'){
			curr ++;
		} 
		else {
			curr = 0;
		}
		if (curr > max){
			max = curr;
		}

	}
	cout << max;
}