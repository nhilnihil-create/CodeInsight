#include <iostream>
#include <vector>
#include<string>

using namespace std;

int main(){

	int sum;
	string data;

	for (;;){//0???????????´????????°????????????

		getline(cin, data);
		sum = 0;

		for (int i = 0; data[i]; i++){

			sum += data[i] - '0';

		}if (sum == 0)break;
		cout << sum << endl;
		
	}




	return 0;
}