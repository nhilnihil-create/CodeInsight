#include <iostream>
#include <string>
using namespace std;

int main(){
	string str,tmp;
	int sum;
	while(1){
		sum = 0;
		cin >> str;
		if( str == "0") break;
		for(int i = 0; i < str.size(); i++){
			tmp = str[i];
			sum += stoi(tmp);
		}
		cout << sum << endl;
	}
	return 0;
}	