#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	long long number = 0;
	string s;
	getline(cin, s);
	
	
	for(int i = 0; i < s.size(); i++){
		// cout << "number" << number << endl << "s[i]" << s[i];
		number += (int)(s[i]-48);
	}
	// cout << number;
	if(number % 9 == 0 || number == 0){
		cout << "Yes";
	} 
	else{
		cout << "No";
	}
		
	return 0;
}