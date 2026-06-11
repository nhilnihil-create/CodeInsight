#include <iostream>
#include<string>
using namespace std;

int main(){
	long long int N;
	string S;
	cin >> N;

	cout << ((N + 999) / 1000) * 1000 - N << endl;
	

}
